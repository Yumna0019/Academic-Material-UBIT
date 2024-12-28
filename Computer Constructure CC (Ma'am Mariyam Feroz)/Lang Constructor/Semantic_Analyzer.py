class SemanticAnalyzer:
    def __init__(self, ast):
        self.ast = ast
        self.symbol_table = {}
        self.functions = {}
        self.classes = {}
        self.current_scope = None

    def analyze(self):
        for statement in self.ast:
            self.analyze_statement(statement, inherited=None)

    def analyze_statement(self, statement, inherited):
        if "type" not in statement:
            raise Exception("Unknown statement type")

        if statement["type"] == "var_declaration":
            return self.analyze_var_declaration(statement, inherited)
        elif statement["type"] == "var_initialization":
            return self.analyze_var_initialization(statement, inherited)
        elif statement["type"] == "class":
            return self.analyze_class(statement, inherited)
        elif statement["type"] == "if":
            return self.analyze_conditional(statement, inherited)
        elif statement["type"] == "function_calling":
            return self.analyze_function_calling(statement, inherited)
        elif statement["type"] == "function":
            return self.analyze_function(statement, inherited)
        elif statement["type"] == "loop":
            return self.analyze_loop(statement, inherited)
        elif statement["type"] == "expression":
            return self.analyze_expression(statement, inherited)
        elif statement["type"] == "print":
            return self.analyze_print(statement, inherited)
        elif statement["type"] == "input":
            return self.analyze_input(statement, inherited)
        elif statement["type"] == "object":
            return self.analyze_object(statement, inherited)
        elif statement["type"] == "object_calling":
            return self.analyze_object_calling(statement, inherited)
        elif statement["type"] == "array_declaration":
            return self.analyze_array_declaration(statement, inherited)
        elif statement["type"] == "array_initialization":
            return self.analyze_array_initialization(statement, inherited)

    def analyze_var_declaration(self, statement, inherited):
        var_name = statement['name']
        if var_name in self.symbol_table:
            raise Exception(f"Variable '{var_name}' is already declared.")
        var_type = inherited if inherited else statement.get('data_type', 'double')

        if var_type not in ['double', 'string']: 
            raise Exception(f"Unsupported type '{var_type}' for variable '{var_name}'.")

        self.symbol_table[var_name] = {'type': var_type}
        statement['attributes'] = {'type': var_type}
        return var_type

    def analyze_var_initialization(self, statement, inherited):
        var_name = statement['name']
        if var_name not in self.symbol_table:
            raise Exception(f"Variable '{var_name}' used without declaration.")

        value_type = self.analyze_expression(statement['value'], inherited)
        declared_type = self.symbol_table[var_name]['type']
        if value_type != declared_type:
            raise Exception(f"Type mismatch: '{var_name}' declared as '{declared_type}', initialized with '{value_type}'.")

        return value_type

    def analyze_function(self, statement, inherited):
        func_name = statement["name"]
        if func_name in self.functions:
            raise Exception(f"Function '{func_name}' is already declared.")
        params = statement.get("parameters", [])
        return_type = statement.get("data_type", "void")
        self.functions[func_name] = {
            "parameters": params,
            "return_type": return_type
        }
        self.analyze_block(statement['body'], inherited=return_type)
        return return_type  

    def analyze_expression(self, expression, inherited):
        if isinstance(expression, dict):
            if "type" in expression:
                if expression["type"] == "number":
                    return 'double'
                elif expression["type"] == "string":
                    return 'string'
                elif expression["type"] == "value":  
                    return 'double' 
                elif expression["type"] == "double":  
                    return 'double'
                else:
                    raise Exception(f"Unknown expression type: {expression['type']}")
            else:
                raise Exception("Invalid expression format")
        else:
            raise Exception("Invalid expression type")


    def analyze_conditional(self, statement, inherited):
        condition_type = self.analyze_expression(statement['condition'], inherited)
        self.analyze_block(statement['true_block'], inherited)
        if 'false_block' in statement:
            self.analyze_block(statement['false_block'], inherited)
        return condition_type  

    def analyze_loop(self, statement, inherited):
        condition_type = self.analyze_expression(statement['condition'], inherited)
        self.analyze_block(statement['block'], inherited)
        return condition_type 


    def analyze_function_calling(self, statement, inherited):
        func_name = statement["name"]
        if func_name not in self.functions:
            raise Exception(f"Function '{func_name}' is called but not defined.")
        expected_params = self.functions[func_name]["parameters"]
        actual_args = statement.get("arguments", [])
        if len(expected_params) != len(actual_args):
            raise Exception(f"Function '{func_name}' expects {len(expected_params)} arguments, but got {len(actual_args)}.")
        for arg in actual_args:
            self.analyze_expression(arg, inherited)
        return self.functions[func_name]['return_type']  

    def analyze_object_calling(self, statement, inherited):
        object_name = statement["object_name"]
        method_name = statement["method_name"]
        if object_name not in self.symbol_table:
            raise Exception(f"Object '{object_name}' used without declaration.")
        if method_name not in self.symbol_table[object_name]["methods"]:
            raise Exception(f"Method '{method_name}' does not exist in object '{object_name}'.")
        return self.symbol_table[object_name]["methods"][method_name]["return_type"]

    def analyze_object(self, statement, inherited):
        class_name = statement["class_type"]
        if class_name not in self.classes:
            raise Exception(f"Class '{class_name}' is not declared.")
        return "object"

    def analyze_array_declaration(self, statement, inherited):
        array_name = statement['name']
        array_type = statement['data_type']
        self.symbol_table[array_name] = {'type': array_type, 'is_array': True}
        return array_type

    def analyze_array_initialization(self, statement, inherited):
        array_name = statement['name']
        if array_name not in self.symbol_table:
            raise Exception(f"Array '{array_name}' used without declaration.")
        
        declared_type = self.symbol_table[array_name]['type']
        elements = statement['value']['elements']
        for element in elements:
            element_type = self.analyze_expression(element, inherited)
            if element_type != declared_type:
                raise Exception(f"Type mismatch: Array '{array_name}' expects elements of type '{declared_type}', "
                                f"but got '{element_type}'.")

        return declared_type

    def analyze_class(self, statement, inherited):
        class_name = statement['class_name']
        if class_name in self.classes:
            raise Exception(f"Class '{class_name}' is already declared.")
        self.classes[class_name] = statement
        self.analyze_block(statement['block'], inherited)
        return 'class'

    def analyze_print(self, statement, inherited):
        var_name = statement["variable"]["name"]
        if var_name not in self.symbol_table:
            raise Exception(f"Variable '{var_name}' used without declaration.")
        return self.symbol_table[var_name]['type']

    def analyze_input(self, statement, inherited):
        var_name = statement["variable"]["name"]
        if var_name not in self.symbol_table:
            raise Exception(f"Variable '{var_name}' used without declaration.")
        return self.symbol_table[var_name]['type']

    def analyze_block(self, block, inherited):
        for stmt in block['statements']:
            self.analyze_statement(stmt, inherited)

    def print_attributed_ast(self):
        import json
        print(json.dumps(self.ast, indent=2))

ast = [
# variable_declaration
    {
        "type": "variable_declaration",
        "data_type": "string",
        "name": "hello",
    },
# variable_initialization
    {
        "type": "variable_initialization",
        "data_type": "double",
        "name": "x",
        "value": {"type": "number", "value": 0}
    },
# function_declaration
    {
        "type": "function_declaration",
        "name": "myFunction",
        "arguments": [
            {"type": "double", "name": "number"}
        ],
        "body": {
            "statements": []
        }
    },
# function call
    {
        "type": "function_call",
        "name": "myFunction",
        "arguments": [
            {"type": "value", "value": 5},
        ]
    },
# loop
    {
        "type": "loop",
        "condition": {"type": "value", "value": 1},
        "block": {
            "statements": []
        }
    },
# conditions if-else
    {
        "type": "if",
        "condition": {"type": "double", "name": "x"},
        "true_block": {
        "statements": [] 
        },
        "false_block": {
            "statements": []  
        }
    },
# array_declaration
    {
        "type": "array_declaration",
        "data_type": "double",
        "name": "arr1",
    },
# array_initialization
    {
        "type": "array_initialization",
        "name": "arr1",
        "value": {
            "type": "array_initialization",
            "elements": [
                {"type": "number", "value": 1.0},
                {"type": "number", "value": 2.0},
                {"type": "number", "value": 3.0},
            ]
        }
    },
# class
    {
        "type": "class",
        "class_name": "myClass",
        "block": {
            "statements": []
        }
    },
# object 
    {
        "type": "object",
        "class_type": "myClass",
        "name": "myObject"
    },
# object call
    {
        "type": "object_call",
        "object_name": "myObject",
        "method_name": "myFunction",
        "arguments": [
            {"type": "value", "value": 22},  
            {"type": "value", "value": "code"}
        ]
    }
]


analyzer = SemanticAnalyzer(ast)
try:
    analyzer.analyze()
    print("Semantic analysis passed!")
    analyzer.print_attributed_ast()  # Print the attributed AST
except Exception as e:
    print(f"Semantic analysis error: {e}")




