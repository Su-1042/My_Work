##################### BOILERPLATE BEGINS ############################

# Token types enumeration
##################### YOU CAN CHANGE THE ENUMERATION IF YOU WANT #######################
class TokenType:
    IDENTIFIER = "IDENTIFIER"
    KEYWORD = "KEYWORD"
    INTEGER = "INTEGER"
    FLOAT = "FLOAT"
    SYMBOL = "SYMBOL"

# Token hierarchy dictionary
token_hierarchy = {
    "if": TokenType.KEYWORD,
    "else": TokenType.KEYWORD,
    "print": TokenType.KEYWORD
}


# helper function to check if it is a valid identifier
def is_valid_identifier(lexeme):
    if not lexeme:
        return False

    # Check if the first character is an underscore or a letter
    if not (lexeme[0].isalpha() or lexeme[0] == '_'):
        return False

    # Check the rest of the characters (can be letters, digits, or underscores)
    for char in lexeme[1:]:
        if not (char.isalnum() or char == '_'):
            return False

    return True


# Tokenizer function
def tokenize(source_code):
    tokens = []
    position = 0

    while position < len(source_code):
        # Helper function to check if a character is alphanumeric
        def is_alphanumeric(char):
            return char.isalpha() or char.isdigit() or (char=='_')

        char = source_code[position]

        # Check for whitespace and skip it
        if char.isspace():
            position += 1
            continue

        # Identifier recognition
        if char.isalpha():
            lexeme = char
            position += 1
            while position < len(source_code) and is_alphanumeric(source_code[position]):
                lexeme += source_code[position]
                position += 1

            if lexeme in token_hierarchy:
                token_type = token_hierarchy[lexeme]
            else:
                # check if it is a valid identifier
                if is_valid_identifier(lexeme):
                    token_type = TokenType.IDENTIFIER
                else:
                    raise ValueError(f"Invalid identifier: {lexeme}")

        # Integer or Float recognition
        elif char.isdigit():
            lexeme = char
            position += 1

            is_float = False
            while position < len(source_code):
                next_char = source_code[position]
                # checking if it is a float, or a full-stop
                if next_char == '.':
                    if (position + 1 < len(source_code)):
                        next_next_char = source_code[position+1]
                        if next_next_char.isdigit():
                            is_float = True

                # checking for illegal identifier
                elif is_alphanumeric(next_char) and not next_char.isdigit():
                    while position < len(source_code) and is_alphanumeric(source_code[position]):
                        lexeme += source_code[position]
                        position += 1
                    if not is_valid_identifier(lexeme):
                        raise ValueError(f"Invalid identifier: {str(lexeme)}\nIdentifier can't start with digits")

                elif not next_char.isdigit():
                    break

                lexeme += next_char
                position += 1

            token_type = TokenType.FLOAT if is_float else TokenType.INTEGER

        # Symbol recognition
        else:
            lexeme = char
            position += 1
            token_type = TokenType.SYMBOL

        tokens.append((token_type, lexeme))

    return tokens

########################## BOILERPLATE ENDS ###########################

R = {
    "S": ["FA", "SS", "y"],
    "A": ["CS", "CL"],
    "L": ["SM"],
    "M": ["ES"],
    "C": ["y", "XN","r"],
    "N": ["OX"],
    "O": ["+", "-", "*", "/", "^", ">", "<", "="],
    "F": ["if"],
    "E": ["else"],
    "X": ["r", "XN", "y"],
}
    
    # r is the set of real numbers
    # y is the set that is the union of numbers, keywords, identifiers (aoart from if and else Ss)

def checkGrammar(tokens):
    # CNF grammar
    # Function to perform the CYK Algorithm
    n = len(tokens)
    
    non_terminals = list(R.keys())
    modified_tokens = []
    # print(tokens[0])
    for token in tokens:
        if token[0] == TokenType.FLOAT or  token[0] == TokenType.INTEGER  or  token[0] == TokenType.IDENTIFIER or token[1] == "print":
            modified_tokens.append("y")
        
        elif token[0] == TokenType.FLOAT or token[0] == TokenType.INTEGER:
            modified_tokens.append ("r")
             
        else:
            modified_tokens.append(token[1])
        

    # Initialize the table
    table = [[set([]) for j in range(n)] for i in range(n)]
 
    for i in range(n):
        for non_terminal in non_terminals:
            if modified_tokens[i] in R[non_terminal]:
                table[i][i].add(non_terminal)

    # Fill in the table for substrings of length greater than 1
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            for k in range(i, j):
                for non_terminal in non_terminals:
                    for production in R[non_terminal]:
                        if len(production) == 2:
                            left, right = production
                            if left in table[i][k] and right in table[k + 1][j]:
                                table[i][j].add(non_terminal)
                                            
    # If word can be formed by rules
    # of given grammar
    if len(table[0][n-1]) != 0:
        print("True")
    else:
        print("Syntax Error")



# Test the tokenizer
if __name__ == "__main__":
    source_code = "if 2 + print print 5"
    w = source_code
    tokens = tokenize(source_code)
    for token in tokens:
        print(f"Token Type: {token[0]}, Token Value: {token[1]}")

    logs = checkGrammar(tokens)  # You are tasked with implementing the function checkGrammar