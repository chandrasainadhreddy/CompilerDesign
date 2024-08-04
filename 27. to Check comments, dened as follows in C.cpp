#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 100
#define KEYWORDS_COUNT 5

char keywords[KEYWORDS_COUNT][MAX_ID_LEN] = {"if", "else", "while", "return", "int"};

int isKeyword(char* str) {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '!';
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

    
        if (code[i] == '/' && code[i + 1] == '/') {
            printf("Single-line comment: ");
            while (code[i] != '\n' && code[i] != '\0') {
                putchar(code[i]);
                i++;
            }
            printf("\n");
            continue;
        }

  
        if (code[i] == '/' && code[i + 1] == '*') {
            printf("Multi-line comment: ");
            i += 2;
            while (code[i] != '*' || code[i + 1] != '/') {
                if (code[i] == '\0') {
                    printf("Error: Unterminated comment\n");
                    return;
                }
                putchar(code[i]);
                i++;
            }
            printf("*/\n");
            i += 2;
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
            if (isKeyword(currentToken)) {
                printf("Keyword: %s\n", currentToken);
            } else {
                printf("Identifier: %s\n", currentToken);
            }
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


        if (isOperator(code[i])) {
            printf("Operator: %c\n", code[i]);
            i++;
            continue;
        }

 
        printf("Unrecognized character: %c\n", code[i]);
        i++;
    }
}

int main() {
    const char* code = "int main() { int a = 5; // this is a single-line comment\n /* this is a\nmulti-line comment */ a = a + 10; return 0; }";
    lexicalAnalyzer(code);
    return 0;
}
