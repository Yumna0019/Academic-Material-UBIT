import re  

# Pattern for identifiers
identifier = r'^(A[a-zA-Z0-9^]*|[a-zA-Z][a-zA-Z0-9^]*)$'  

# Pattern for double 
double = r'\b[+-]?(\d*\.\d+|\d+\.?)([eE][+-]?\d+)?\b'

# Pattern for string 
A = r"[\\'|\"|\\]"  # \",\',\\
B = r"[bntro]"    # with or without backslash 
C = r"[@+:!.]"       # Not allowed with a backslash
D = r"[a-zA-Z\s+_=]" # Letters , space ,_,+,= allowed

char_const = rf"(\\{A}|\\{B}|{B}|{C}|{D})"
str_pattern = rf'^"({char_const})*"$'

# Dictionaries for keywords, operators, and punctuators
keywords = {
    'double': 'DT',    # DT = Data Type
    'str': 'String', 
    'void': 'void', 
    'loop': 'Loop', 
    'br': 'Break',
    'if': 'if',  
    'else': 'else', 
    'prnt': 'Print',
    'inp': 'input', 
    'retn': 'return', 
    'class': 'class', 
    'extends': 'extends',
    'supr': 'Super', 
    'this': 'This', 
    'pub': 'AM',        # Access Modifier
    'pri': 'AM',
    'final': 'Final', 
    'new': 'new', 
    'arr': 'Array', 
    'and': 'And', 
    'or': 'Or',
    'not': 'Not'
}
operators = {
    "+": "PM",       # PM = Plus Minus 
    "-": "PM", 
    "*": "MDM",      # MDM = Multiple Divide Modulo
    "/": "MDM", 
    "%": "MDM", 
    "<": "ROP",      # ROP = Relational Operator
    ">": "ROP", 
    "<=": "ROP", 
    ">=": "ROP", 
    "!": "ROP", 
    "!=": "ROP", 
    "==": "ROP",
    "++": "INC_DEC", 
    "--": "INC_DEC", 
    "=": "=", 
}
punctuators = {
    '(': '(', 
    ')': ')', 
    '{': '{', 
    '}': '}', 
    '[': '[', 
    ']': ']', 
    '.': '.', 
    ';': ';', 
    ',': ','
}

class Token:    # Token Class
    def __init__(self, value, token_type, line):
        self.value = value  
        self.type = token_type 
        self.line = line  

    def __repr__(self):
        # return f"Token Set (value='{self.value}', type='{self.type}', line={self.line})"
        return f"Token ('{self.value}', '{self.type}', {self.line}),"

def read_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()  # Read all lines from the file
    return lines

# Token Function for Dot (.)
def handle_dot_token(token, line_number):
    token_classes = []
    segments = re.split(r'(\.)', token) 

    i = 0
    while i < len(segments):
        if not segments[i].strip():  
            i += 1
            continue
        
        if segments[i].isdigit() and i + 2 < len(segments) and segments[i + 1] == '.' and segments[i + 2].isdigit():
            # Handle cases like '123.456'
            token_classes.append(Token(f"{segments[i]}.{segments[i + 2]}", 'DOUBLE', line_number))
            i += 3
        elif segments[i] == '.':
            # Handle cases like '.123' or '.'
            if i + 1 < len(segments) and re.fullmatch(r'\d+([eE][+-]?\d+)?', segments[i + 1]):
                token_classes.append(Token(f".{segments[i + 1]}", 'DOUBLE', line_number))
                i += 2
            else:
                token_classes.append(Token(segments[i], 'DOT', line_number))
                i += 1
        else:
            # Handle tokens without dots
            if re.fullmatch(double, segments[i]):
                token_classes.append(Token(segments[i], 'DOUBLE', line_number))
            elif re.fullmatch(identifier, segments[i]):
                token_classes.append(Token(segments[i], 'IDENTIFIER', line_number))
            else:
                token_classes.append(Token(segments[i], 'INVALID LEXEME', line_number))
            i += 1

    return token_classes

# Token Function for operators or punctuators 
def handle_mixed_token(token, line_number):
    token_classes = []
    if '.' in token:
        token_classes.extend(handle_dot_token(token, line_number))
    else:
        i = 0
        while i < len(token):
            matched = False

            for op in sorted(operators.keys(), key=len, reverse=True):
                if token[i:i + len(op)] == op:
                    token_classes.append(Token(op, operators[op], line_number))
                    i += len(op)
                    matched = True
                    break

            for p in sorted(punctuators.keys(), key=len, reverse=True):
                if token[i:i + len(p)] == p:
                    token_classes.append(Token(p, punctuators[p], line_number))
                    i += len(p)
                    matched = True
                    break

            if not matched:    # if not operators and punctuators
                start = i
                while i < len(token) and (token[i].isalnum() or token[i] == '^'):
                    i += 1
                potential_token = token[start:i]
                if re.fullmatch(double, potential_token):
                    token_classes.append(Token(potential_token, 'DOUBLE', line_number))
                elif re.fullmatch(identifier, potential_token):
                    token_classes.append(Token(potential_token, 'IDENTIFIER', line_number))
                else:
                    token_classes.append(Token(potential_token, 'INVALID LEXEME', line_number))

    return token_classes



def classify_tokens(lines):
    token_classes = []
    inside_multiline_comment = False
    inside_string = False
    string_literal = ''
    line_number_of_string_start = 0

    for line_number, line in enumerate(lines, start=1):
        if inside_multiline_comment:      # for Multi Line comment $$
            if '$$' in line:
                inside_multiline_comment = False
                line = line.split('$$', 1)[1]
            else:
                continue

        if '$$' in line and line.strip().startswith('$$'):
            inside_multiline_comment = True
            continue

        if '$' in line and not inside_multiline_comment:      # for Single Lin comment $
            line = line.split('$', 1)[0]

        # Breakwords
        tokens = re.findall(r'(?:[^\s\(\)\{\}\[\],;"]+|[;,(){}\[\]]|"(?:\\.|[^"\\])*"?)', line)
        i = 0
        while i < len(tokens):
            token = tokens[i]

            if inside_string:          # for String
                string_literal += " " + token
                if token.endswith('"') and not token.endswith(r'\"'):
                    inside_string = False
                    string_literal = string_literal.strip()
                    if string_literal.endswith('""'):
                        string_literal = string_literal[:-1].strip()
                    if re.fullmatch(str_pattern, string_literal):
                        token_classes.append(Token(string_literal, 'String', line_number_of_string_start))
                    else:
                        token_classes.append(Token(string_literal, 'INVALID STRING', line_number_of_string_start))
                    string_literal = ''
                i += 1
                continue

            if token.startswith('"'):
                inside_string = True
                line_number_of_string_start = line_number
                string_literal = token
                if token.endswith('"') and not token.endswith(r'\"'):
                    inside_string = False
                    string_literal = string_literal.strip()
                    if re.fullmatch(str_pattern, string_literal):
                        token_classes.append(Token(string_literal, 'String', line_number_of_string_start))
                    else:
                        token_classes.append(Token(string_literal, 'INVALID STRING', line_number_of_string_start))
                    string_literal = ''
                i += 1
                continue

            if any(op in token for op in operators) or any(p in token for p in punctuators):
                token_classes.extend(handle_mixed_token(token, line_number))
            elif token in keywords:
                token_classes.append(Token(token, keywords[token], line_number))
            elif re.fullmatch(double, token):
                token_classes.append(Token(token, 'DOUBLE', line_number))
            elif token in operators:
                token_classes.append(Token(token, operators[token], line_number))
            elif token in punctuators:
                token_classes.append(Token(token, punctuators[token], line_number))
            elif re.fullmatch(identifier, token):
                token_classes.append(Token(token, 'IDENTIFIER', line_number))
            else:
                token_classes.append(Token(token, 'INVALID LEXEME', line_number))
            i += 1

    if inside_string:
        token_classes.append(Token(string_literal.strip(), 'INVALID LEXEME', line_number_of_string_start))

    return token_classes

def output_results(token_classes):
    for token in token_classes:
        print(token)

if __name__ == "__main__":
    file_path = "input.txt"
    lines = read_file(file_path)
    token_classes = classify_tokens(lines)
    output_results(token_classes)

