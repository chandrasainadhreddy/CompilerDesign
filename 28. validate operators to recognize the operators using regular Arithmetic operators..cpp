#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 100

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int isDelimiter(char ch) {
    return isspace(ch) || ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

void lexicalAnalyzer(const char* code) {
    int i = 0;
    char currentToken[MAX_ID_LEN];
    int tokenIndex = 0;

    while (code[i] != '\0') {
      
        if (isspace(code[i])) {
            i++;
            continue;
        }

      
        if (isOperator(code[i])) {
            printf("Operator: %c\n", code[i]);
            i++;
            continue;
        }

  
        if (isalpha(code[i]) || code[i] == '_') {
            tokenIndex = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                if (tokenIndex < MAX_ID_LEN - 1) {
                    currentToken[tokenIndex++] = code[i];
                }
                i++;
            }
            currentToken[tokenIndex] = '\0';
            printf("Identifier: %s\n", currentToken);
            continue;
        }

        if (isdigit(code[i])) {
            tokenIndex = 0;
            while (isdigit(code[i])) {
                if (tokenIndex < MAX_ID_LEN - 1) {
                    currentToken[tokenIndex++] = code[i];
                }
                i++;
            }
            currentToken[tokenIndex] = '\0';
            printf("Constant: %s\n", currentToken);
            continue;
        }

 
        if (isDelimiter(code[i])) {
            i++;
            continue;
        }


        printf("Unrecognized character: %c\n", code[i]);
        i++;
    }
}

int main() {
    const char* code = "int a = 5 + 3; a = a - 2 * 10 / 5;";
    lexicalAnalyzer(code);
    return 0;
}
