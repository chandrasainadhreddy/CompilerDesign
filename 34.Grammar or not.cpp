#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if the string satisfies the grammar
int is_valid_expression(const char* str) {
    int i = 0;
    int len = strlen(str);
    
    // The string should not be empty
    if (len == 0) {
        return 0;
    }

    // The first character should be a digit
    if (!isdigit(str[i])) {
        return 0;
    }
    i++;

    // Check the rest of the string
    while (i < len) {
        // Expecting a '+' operator
        if (str[i] != '+') {
            return 0;
        }
        i++;
        
        // Expecting a digit
        if (i >= len || !isdigit(str[i])) {
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    char input[100];

    printf("Enter an expression: ");
    scanf("%s", input);

    if (is_valid_expression(input)) {
        printf("The input string is a valid expression.\n");
    } else {
        printf("The input string is not a valid expression.\n");
    }

    return 0;
}
