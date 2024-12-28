class Token:
    def __init__(self, value_part, class_part, line_number):
        # Initialize a token with value, class type, and line number
        self.value_part = value_part
        self.class_part = class_part
        self.line_number = line_number

    def __repr__(self):
        # String representation for debugging
        return f"Token(value='{self.value_part}', type='{self.class_part}', line={self.line_number})"

class Parser:
    def __init__(self, tokens):
        # Initialize parser with list of tokens
        self.tokens = tokens
        self.current_index = 0  # Track current position in tokens
        self.current_token = tokens[0] if tokens else None  # Start with first token if available

    def eat(self, *token_types):
        #  token if it eates one of the expected types
        if self.current_token and self.current_token.class_part in token_types:
            consumed_token = self.current_token  # Store the token before advancing
            self.current_index += 1
            # Update current token or set to None if end of tokens
            self.current_token = self.tokens[self.current_index] if self.current_index < len(self.tokens) else None
            return consumed_token
        else:
            # Raise error if expected token type does not eat
            raise Exception(f"Syntax error at line {self.current_token.line_number}: expected one of {token_types}, got {self.current_token.class_part if self.current_token else 'EOF'}")

    def parse_program(self):
        """Parse a program consisting of multiple statements."""
        statements = []  # List to store parsed statements
        while self.current_index < len(self.tokens):  # Process all tokens
            statements.append(self.parse_statement())  # Parse each statement
        return statements

    def parse_statement(self):
        """Parse a statement based on the defined grammar."""
        # Parse 'break' statement
        if self.current_token.value_part == "br":
            self.eat("Break")
            return {"type": "Break"}

        # Parse 'this' or 'supr' access statements
        if self.current_token.value_part in {"supr", "this"}:
            return self.parse_access()

        # Parse data type declarations or array declarations
        if self.current_token.class_part in {"DT", "String", "void"}:
            data_type = self.eat("DT", "String", "void").value_part

            # Check for array declaration
            if self.current_token.class_part == "[":
                self.eat("[")
                self.eat("]")
                array_name = self.eat("IDENTIFIER").value_part

                # Check for array initialization
                if self.current_token.class_part == "=":
                    return self.parse_array_initialization(data_type, array_name)
                else:
                    self.eat(";")
                    return {
                        'type': 'array_declaration',
                        'data_type': data_type,
                        'name': array_name
                    }

            # Parse variable or function declaration
            elif self.current_token.class_part == "IDENTIFIER":
                identifier_name = self.eat("IDENTIFIER").value_part

                # Check for function declaration
                if self.current_token.class_part == "(":
                    return self.parse_function(identifier_name, data_type)
                else:
                    # Parse variable initialization or declaration
                    if self.current_token.class_part == "=":
                        return self.parse_var_initialization(data_type, identifier_name)
                    else:
                        return self.parse_var_declaration(data_type, identifier_name)

        # Handle identifier for object or function calls
        elif self.current_token.class_part == "IDENTIFIER":
            next_token = self.tokens[self.current_index + 1]

            # Object declaration or calling
            if next_token.class_part == "IDENTIFIER":
                return self.parse_object()
            elif next_token.class_part == "DOT":
                return self.parse_object_calling()
            elif next_token.class_part == "(":
                return self.parse_function_calling()

        # Parse control structures: if, loop, print, input, return
        elif self.current_token.class_part == "if":
            return self.parse_conditional()
        elif self.current_token.class_part == "Loop":
            return self.parse_loop()
        elif self.current_token.class_part == "Print":
            return self.parse_print()
        elif self.current_token.class_part == "input":
            return self.parse_input()
        elif self.current_token.class_part == "AM":
            return self.parse_class()
        elif self.current_token.class_part == "void":
            return self.parse_function()
        elif self.current_token.class_part == "return":
            return self.parse_return()
        else:
            # Raise error if unexpected token found
            raise Exception(f"Unexpected token: {self.current_token.class_part}")

    def parse_function(self, identifier_name, data_type):
        """Parse a function definition with parameters and a body block."""
        self.eat("(")  # Match opening parenthesis

        parameters = []  # List to store function parameters
        while self.current_token.class_part != ")":
            # Parse parameter type and name
            if self.current_token.class_part in {"DT", "String"}:
                param_type = self.eat("DT", "String").class_part
                param_name = self.eat("IDENTIFIER").value_part
                parameters.append({"type": param_type, "name": param_name})

                if self.current_token.class_part == ",":
                    self.eat(",")  # Match comma separating parameters
            else:
                raise Exception(f"Expected parameter type, got: {self.current_token.class_part}")

        self.eat(")")  # Match closing parenthesis
        block = self.parse_block()  # Parse function body block

        return {
            'type': 'function_definition',
            'name': identifier_name,
            'data_type': data_type,
            'parameters': parameters,
            'body': block
        }

    def parse_var_declaration(self, data_type, variable_name):
        """Parse variable declaration: <data_type> <variable_name>;"""
        self.eat(";")  # Match semicolon ending declaration
        return {'type': 'var_declaration', 'data_type': data_type, 'name': variable_name}

    def parse_var_initialization(self, data_type, variable_name):
        """Parse variable initialization, e.g., 'double c = a + b;' or 'double c = 3.14;'."""
        self.eat("=")  # Match assignment operator
        
        # Try parsing based on the expected data type
        if data_type == "double":
            # Parse either a complex expression or a simple double literal
            if self.current_token.class_part in ["IDENTIFIER", "NUMBER", "(", "+", "-", "*", "/"]:
                expression = self.parse_expression()
            else:
                expression = self.parse_Double()  # Directly parse as a double if it's a literal
        elif data_type == "str":
            expression = self.parse_String()  # Parse as a string literal for `str` type
        else:
            raise Exception(f"Unsupported data type: {data_type}")
        
        self.eat(";")  # Match semicolon to end initialization statement
        
        return {
            'type': 'variable_initialization',
            'data_type': data_type,
            'identifier': variable_name,
            'value': expression
        }



    def parse_Double(self):
        """Parse a double/number."""
        # Check if current token is a number and return its value
        if self.current_token.class_part == "DOUBLE":
            return {'type': 'number', 'value': self.eat("DOUBLE").value_part}
        else:
            raise Exception(f"Expected a NUMBER, but got {self.current_token.class_part}")

    def parse_String(self):
        """Parse a string."""
        # Check if current token is a string and return its value
        if self.current_token.class_part == "String":
            return {'type': 'string', 'value': self.eat("String").value_part}
        else:
            raise Exception(f"Expected a STRING, but got {self.current_token.class_part}")

    def parse_expression(self):
        """Parse an expression that can involve identifiers, numbers, and specified operators."""
        left = self.parse_term()  # Parse the left part of the expression

        # Continue parsing if operator is present
        while self.current_token and self.current_token.class_part in ["ROP", "PM", "MDM", "INC_DEC", "="]:
            operator_type = self.current_token.class_part
            operator_value = self.current_token.value_part
            self.eat(self.current_token.class_part)  # Match operator
            right = self.parse_term()  # Parse the right part of the expression
            left = {"type": operator_type, "left": left, "operator": operator_value, "right": right}
        
        return left

    def parse_term(self):
        """Parse a term which can be an identifier or a number."""
        # Check for identifier or number and return appropriate type
        if self.current_token.class_part == "IDENTIFIER":
            identifier = self.current_token.value_part
            self.eat("IDENTIFIER")
            return {"type": "identifier", "name": identifier}
        elif self.current_token.class_part == "DOUBLE":
            value = self.current_token.value_part
            self.eat("DOUBLE")
            return {"type": "number", "value": value}
        else:
            raise Exception(f"Unexpected token in term: {self.current_token}")

    def parse_loop(self):
        """Parse loop structure: loop (...) { statements }."""
        self.eat("Loop")  # Match 'Loop' keyword
        self.eat("(")  # Match opening parenthesis
        condition = self.parse_expression()  # Parse loop condition
        self.eat(")")  # Match closing parenthesis
        block = self.parse_block()  # Parse loop body block
        return {"type": "loop", "condition": condition, "block": block}

    def parse_conditional(self):
        """Parse conditional: if (...) { statements }."""
        self.eat("if")  # Match 'if' keyword
        self.eat("(")  # Match '(' symbol for condition start
        condition = self.parse_expression()  # Parse the condition expression inside 'if'
        self.eat(")")  # Match ')' symbol for condition end
        true_block = self.parse_block()  # Parse the 'if' block when condition is true
        false_block = None
        if self.current_token and self.current_token.value_part == "else":
            self.eat("else")  # Match 'else' keyword if it exists
            false_block = self.parse_block()  # Parse the 'else' block
        return {'type': 'conditional', 'condition': condition, 'true_block': true_block, 'false_block': false_block}

    def parse_block(self):
        """Parse block: { statements }."""
        self.eat("{")  # Match '{' symbol for block start
        statements = []
        while self.current_token and self.current_token.value_part != "}":
            if self.current_token.class_part == "IDENTIFIER":
                statements.append(self.parse_expression())  # Parse expression for identifiers
            else:
                statements.append(self.parse_statement())  # Parse other types of statements
        self.eat("}")  # Match '}' symbol for block end
        self.eat(";")  # Match ';' symbol to end the block
        return {'type': 'block', 'statements': statements}


    def parse_print(self):
        """Parse print: prnt (...);"""
        self.eat("Print")  # Match 'Print' keyword
        self.eat("(")  # Match '(' for start of print statement
        # variable = self.parse_Identifier()  # Parse identifier to print
        if self.current_token.class_part == "String":
            variable = self.parse_String()  # Parse string input
        elif self.current_token.class_part == "IDENTIFIER":
            variable = self.parse_Identifier()  # Parse identifier input
        else:
            raise Exception(f"Unexpected token: {self.current_token.class_part}")  # Raise exception if unexpected token found
        
        self.eat(")")  # Match ')' to end print statement
        self.eat(";")  # Match ';' to end print statement
        return {'type': 'print', 'variable': variable}

    def parse_input(self):
        """Parse imput: inp(...);"""
        self.eat("input")  # Match 'input' keyword
        self.eat("(")  # Match '(' symbol for input start
        
        if self.current_token.class_part == "String":
            variable = self.parse_String()  # Parse string input
        elif self.current_token.class_part == "IDENTIFIER":
            variable = self.parse_Identifier()  # Parse identifier input
        else:
            raise Exception(f"Unexpected token: {self.current_token.class_part}")  # Raise exception if unexpected token found
        
        self.eat(")")  # Match ')' to end input statement
        self.eat(";")  # Match ';' to end input statement
        return {'type': 'input', 'variable': variable}

    def parse_Identifier(self):
        if self.current_token.class_part == "IDENTIFIER": 
            return {'type': 'variable', 'name': self.eat("IDENTIFIER").value_part}  # Return identifier if found
        else:
            raise Exception(f"Unexpected token: {self.current_token.class_part}")  # Raise exception if identifier not found

    def parse_return(self):
        """Parse return: retn(...);"""
        self.eat("return")  # Match 'return' keyword
        self.eat("(")  # Match '(' symbol for return start
        variable = self.parse_Identifier()  # Parse identifier to return
        self.eat(")")  # Match ')' to end return statement
        self.eat(";")  # Match ';' to end return statement
        return {'type': 'retrun', 'variable': variable}

    def parse_array_declaration(self, data_type):
        """Parse array declaration: <DT>[] <id>;"""
        self.eat("[")  # Match '[' for array declaration
        self.eat("]")  # Match ']' to complete array syntax
        variable_name = self.parse_Identifier()  # Parse array identifier
        self.eat(";")  # Match ';' to end array declaration
        return {'type': 'array_declaration', 'data_type': data_type, 'name': variable_name}

    def parse_array_initialization(self, data_type, array_name):
        """Parse array initialization: <identifier> = { <elements> };"""
        self.eat("=")  # Match '=' for initialization
        self.eat("{")  # Match '{' to start elements initialization
        elements = []
        while self.current_token.class_part != "}":
            if data_type == "double" and self.current_token.class_part == "DOUBLE":
                elements.append(float(self.eat("DOUBLE").value_part))  # Add double elements
            elif data_type == "str" and self.current_token.class_part == "String":
                elements.append(self.eat("String").value_part)  # Add string elements
            else:
                raise SyntaxError(f"Unexpected type in array initialization at line {self.current_token.line_number}")  # Handle unexpected types
            
            if self.current_token.class_part == ",":
                self.eat(",")  # Match ',' to continue with more elements
        
        self.eat("}")  # Match '}' to end elements
        self.eat(";")  # Match ';' to end array initialization
        
        return {
            'type': 'array_initialization',
            'data_type': data_type,
            'name': array_name,
            'elements': elements
        }

    def parse_class(self):
        self.eat("AM")  # Match access modifier (AM)
        self.eat("class")  # Match 'class' keyword
        if self.current_index < len(self.tokens) and self.tokens[self.current_index].class_part == "IDENTIFIER":
            class_name = self.eat("IDENTIFIER").value_part  # Get class name

            if (self.current_index < len(self.tokens) and 
                self.tokens[self.current_index].value_part == "extends"):
                self.eat("extends")  # Match 'extends' keyword for inheritance
                parent_class_name = self.eat("IDENTIFIER").value_part  # Get parent class name
                block = self.parse_block()  # Parse class block

                return {
                    'pub/pri': 'Access Modifier',
                    'type': 'inheritance',
                    'name': class_name,
                    'parent': parent_class_name,
                    'block': block
                }
            else:
                block = self.parse_block()  # Parse block without inheritance
                return {
                    'pub/pri': 'Access Modifier',
                    'type': 'class',
                    'name': class_name,
                    'block': block,
                }

    def parse_access(self):
        """Parse `super.identifier` or `this.identifier` access syntax."""
        if self.current_token.value_part in {"supr", "this"}:  # Check for 'super' or 'this' keyword
            access_type = self.current_token.value_part  # Store the access type ('super' or 'this')
            self.eat("IDENTIFIER")  # Move past 'super' or 'this'
            self.eat("DOT")  # Move past the dot ('.') symbol
            identifier = self.eat("IDENTIFIER").value_part  # Store the accessed identifier name

            return {
                'type': f'{access_type}_access',  # Specify access type
                'identifier': identifier  # Store identifier name
            }
        else:
            raise SyntaxError(f"Expected 'super' or 'this' access, got '{self.current_token.value_part}'")

    def parse_arguments(self):
        """Parse arguments for constructors or method calls."""
        arguments = []
        while True:
            if self.current_token.class_part == "IDENTIFIER":  # Check if argument is an identifier
                arguments.append(self.eat("IDENTIFIER").value_part)
            elif self.current_token.class_part in {"NUMBER", "STRING_LITERAL"}:  # Check if argument is number or string
                arguments.append(self.eat("NUMBER", "STRING_LITERAL").value_part)
            else:
                raise Exception(f"Unexpected argument type: {self.current_token.class_part}")
            if self.current_token.class_part == ",":  # Move past commas in argument list
                self.eat(",")
            elif self.current_token.class_part == ")":  # End of argument list
                break
            else:
                raise Exception(f"Expected ',' or ')', got '{self.current_token.class_part}'")

        return arguments

    def parse_object(self):
        """Parse an object creation statement."""
        class_type = self.eat("IDENTIFIER").value_part  # Store class type for object creation
        object_name = self.eat("IDENTIFIER").value_part  # Store object name
        self.eat("=")  # Move past the assignment operator
        if self.current_token.value_part != "new":  # Expect the keyword 'new' for object instantiation
            raise Exception(f"Expected 'new', got {self.current_token.value_part}")
        self.eat("new")
        new_class_type = self.eat("IDENTIFIER").value_part  # Store the class type after 'new'
        if new_class_type != class_type:  # Check if class types eat
            raise Exception(f"Class name miseat: expected '{class_type}', got '{new_class_type}'")
        self.eat("(")
        parameters = []
        if self.current_token.class_part != ")":  # Parse parameters if present
            parameters = self.parse_arguments()
        self.eat(")")
        self.eat(";")  # End of statement

        return {
            "type": "object_creation",
            "class_type": class_type,
            "object_name": object_name,
            "parameters": parameters
        }


    def parse_object_calling(self):
        """Parse an object method call."""
        object_name = self.eat("IDENTIFIER").value_part  # Get the object name
        self.eat("DOT")  # Move past the dot ('.') symbol
        object_name = self.eat("IDENTIFIER").value_part  # Get the method name
        self.eat("(")
        parameters = []
        if self.current_token.class_part != ")":  # Parse parameters if present
            parameters = self.parse_arguments()
        
        self.eat(")")
        self.eat(";")  # End of statement

        return {
            "type": "method_call",
            "object_name": object_name,
            "object_name": object_name,
            "parameters": parameters
        }

    def parse_function_calling(self):
        """Parse a function call based on the given tokens."""
        function_name = self.current_token.value_part  # Store function name
        self.eat("IDENTIFIER")  

        self.eat("(")
        arguments = []

        if self.current_token.class_part != ")":  # Parse arguments if present
            while True:
                if self.current_token.class_part == "IDENTIFIER":  # Check if argument is identifier
                    arguments.append(self.is_identifier())
                elif self.current_token.class_part == "STRING":  # Check if argument is string
                    arguments.append(self.eat("STRING").value_part)
                elif self.current_token.class_part == "DOUBLE":  # Check if argument is double
                    arguments.append(self.eat("DOUBLE").value_part)
                else:
                    raise Exception(f"Unexpected argument type: {self.current_token.class_part}")
                
                if self.current_token.class_part == ",":  # Move past commas
                    self.eat(",")
                elif self.current_token.class_part == ")":  # End of argument list
                    break
            
        self.eat(")")
        self.eat(";")  # End of statement
        return {
            "type": "function_calling",
            "name": function_name,
            "arguments": arguments
        }


tokens = [
Token ('void', 'void', 5),
Token ('myFunction', 'IDENTIFIER', 5),
Token ('(', '(', 5),
Token (')', ')', 5),
Token ('{', '{', 5),
Token ('double', 'DT', 6),
Token ('i', 'IDENTIFIER', 6),
Token ('=', '=', 6),
Token ('1', 'DOUBLE', 6),
Token (';', ';', 6),
Token ('loop', 'Loop', 7),
Token ('(', '(', 7),
Token ('i', 'IDENTIFIER', 7),
Token ('<', 'ROP', 7),
Token ('5', 'DOUBLE', 7),
Token (')', ')', 7),
Token ('{', '{', 7),
Token ('if', 'if', 8),
Token ('(', '(', 8),
Token ('i', 'IDENTIFIER', 8),
Token ('==', 'ROP', 8),
Token ('3', 'DOUBLE', 8),
Token (')', ')', 8),
Token ('{', '{', 8),
Token ('br', 'Break', 9),
Token ('}', '}', 10),
Token (';', ';', 10),
Token ('else', 'else', 11),
Token ('{', '{', 11),
Token ('i', 'IDENTIFIER', 12),
Token ('=', '=', 12),
Token ('i', 'IDENTIFIER', 12),
Token ('+', 'PM', 12),
Token ('2', 'DOUBLE', 12),
Token ('}', '}', 13),
Token (';', ';', 13),
Token ('i', 'IDENTIFIER', 14),
Token ('=', '=', 14),
Token ('i', 'IDENTIFIER', 14),
Token ('+', 'PM', 14),
Token ('1', 'DOUBLE', 14),
Token ('prnt', 'Print', 15),
Token ('(', '(', 15),
Token ('i', 'IDENTIFIER', 15),
Token (')', ')', 15),
Token (';', ';', 15),
Token ('}', '}', 16),
Token (';', ';', 16),
Token ('}', '}', 17),
Token (';', ';', 17),
Token ('str', 'String', 20),
Token ('name', 'IDENTIFIER', 20),
Token (';', ';', 20),
Token ('double', 'DT', 21),
Token ('age', 'IDENTIFIER', 21),
Token (';', ';', 21),
Token ('double', 'DT', 22),
Token ('score', 'IDENTIFIER', 22),
Token ('=', '=', 22),
Token ('10.0', 'DOUBLE', 22),
Token (';', ';', 22),
Token ('str', 'String', 23),
Token ('greeting', 'IDENTIFIER', 23),
Token ('=', '=', 23),
Token ('"Hello world!"', 'String', 23),
Token (';', ';', 23),
Token ('void', 'void', 26),
Token ('getInput', 'IDENTIFIER', 26),
Token ('(', '(', 26),
Token (')', ')', 26),
Token ('{', '{', 26),
Token ('inp', 'input', 27),
Token ('(', '(', 27),
Token ('"Enter your name: "', 'String', 27),
Token (')', ')', 27),
Token (';', ';', 27),
Token ('}', '}', 28),
Token (';', ';', 28),
Token ('double', 'DT', 31),
Token ('calculate', 'IDENTIFIER', 31),
Token ('(', '(', 31),
Token ('double', 'DT', 31),
Token ('a', 'IDENTIFIER', 31),
Token (',', ',', 31),
Token ('double', 'DT', 31),
Token ('b', 'IDENTIFIER', 31),
Token (')', ')', 31),
Token ('{', '{', 31),
Token ('double', 'DT', 32),
Token ('c', 'IDENTIFIER', 32),
Token ('=', '=', 32),
Token ('a', 'IDENTIFIER', 32),
Token ('+', 'PM', 32),
Token ('b', 'IDENTIFIER', 32),
Token (';', ';', 32),
Token ('retn', 'return', 33),
Token ('(', '(', 33),
Token ('c', 'IDENTIFIER', 33),
Token (')', ')', 33),
Token (';', ';', 33),
Token ('}', '}', 34),
Token (';', ';', 34),
Token ('double', 'DT', 37),
Token ('[', '[', 37),
Token (']', ']', 37),
Token ('scores', 'IDENTIFIER', 37),
Token ('=', '=', 37),
Token ('{', '{', 37),
Token ('1', 'DOUBLE', 37),
Token (',', ',', 37),
Token ('2', 'DOUBLE', 37),
Token (',', ',', 37),
Token ('3', 'DOUBLE', 37),
Token ('}', '}', 37),
Token (';', ';', 37),
Token ('str', 'String', 38),
Token ('[', '[', 38),
Token (']', ']', 38),
Token ('names', 'IDENTIFIER', 38),
Token ('=', '=', 38),
Token ('{', '{', 38),
Token ('"Alice"', 'String', 38),
Token (',', ',', 38),
Token ('"Bob"', 'String', 38),
Token ('}', '}', 38),
Token (';', ';', 38),
Token ('pub', 'AM', 41),
Token ('class', 'class', 41),
Token ('Animal', 'IDENTIFIER', 41),
Token ('{', '{', 41),
Token ('void', 'void', 42),
Token ('makeSound', 'IDENTIFIER', 42),
Token ('(', '(', 42),
Token (')', ')', 42),
Token ('{', '{', 42),
Token ('prnt', 'Print', 43),
Token ('(', '(', 43),
Token ('"Animal sound"', 'String', 43),
Token (')', ')', 43),
Token (';', ';', 43),
Token ('}', '}', 44),
Token (';', ';', 44),
Token ('}', '}', 45),
Token (';', ';', 45),
Token ('pub', 'AM', 47),
Token ('class', 'class', 47),
Token ('Dog', 'IDENTIFIER', 47),
Token ('extends', 'extends', 47),
Token ('Animal', 'IDENTIFIER', 47),
Token ('{', '{', 47),
Token ('void', 'void', 48),
Token ('bark', 'IDENTIFIER', 48),
Token ('(', '(', 48),
Token (')', ')', 48),
Token ('{', '{', 48),
Token ('prnt', 'Print', 49),
Token ('(', '(', 49),
Token ('"Dog barks!"', 'String', 49),
Token (')', ')', 49),
Token (';', ';', 49),
Token ('}', '}', 50),
Token (';', ';', 50),
Token ('}', '}', 51),
Token (';', ';', 51),
Token ('Dog', 'IDENTIFIER', 55),
Token ('dog', 'IDENTIFIER', 55),
Token ('=', '=', 55),
Token ('new', 'new', 55),
Token ('Dog', 'IDENTIFIER', 55),
Token ('(', '(', 55),
Token (')', ')', 55),
Token (';', ';', 55),
Token ('dog', 'IDENTIFIER', 58),
Token ('.', 'DOT', 58),
Token ('bark', 'IDENTIFIER', 58),
Token ('(', '(', 58),
Token (')', ')', 58),
Token (';', ';', 58),
Token ('getInput', 'IDENTIFIER', 61),
Token ('(', '(', 61),
Token (')', ')', 61),
Token (';', ';', 61),
Token ('calculate', 'IDENTIFIER', 62),
Token ('(', '(', 62),
Token ('55', 'DOUBLE', 62),
Token (',', ',', 62),
Token ('45', 'DOUBLE', 62),
Token (')', ')', 62),
Token (';', ';', 62),


]
parser = Parser(tokens)
ast = parser.parse_program()

print(ast)  # Output the abstract syntax tree (AST)
