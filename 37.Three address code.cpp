#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent three-address code instructions
typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} TAC;

// Global variables to keep track of the TAC instructions and temporary variable count
TAC tac[100];
int tacCount = 0;
int tempVarCount = 0;

// Function to create a new temporary variable
void newTemp(char* temp) {
    sprintf(temp, "t%d", tempVarCount++);
}

// Function to add a TAC instruction
void addTAC(const char* op, const char* arg1, const char* arg2, const char* result) {
    strcpy(tac[tacCount].op, op);
    strcpy(tac[tacCount].arg1, arg1);
    strcpy(tac[tacCount].arg2, arg2);
    strcpy(tac[tacCount].result, result);
    tacCount++;
}

// Function to generate TAC for an expression
void generateTAC(const char* expr, char* result) {
    int len = strlen(expr);
    int i = 0;
    char temp1[10], temp2[10], temp3[10];

    // Handle single operand (e.g., 'a')
    if (len == 1) {
        strcpy(result, expr);
        return;
    }

    // Find the main operator (the last operator in the expression for simplicity)
    for (i = len - 1; i >= 0; i--) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            break;
        }
    }

    // Generate TAC for the left and right subexpressions
    char left[10], right[10];
    strncpy(left, expr, i);
    left[i] = '\0';
    strcpy(right, expr + i + 1);

    generateTAC(left, temp1);
    generateTAC(right, temp2);

    // Create a new temporary variable for the result of this operation
    newTemp(temp3);
    addTAC(&expr[i], temp1, temp2, temp3);

    // Set the result to the temporary variable
    strcpy(result, temp3);
}

// Function to display the generated TAC
void displayTAC() {
    printf("\nThree-Address Code:\n");
    for (int i = 0; i < tacCount; i++) {
        printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }
}

int main() {
    char expr[100];
    char result[10];

    printf("Enter an expression: ");
    scanf("%s", expr);

    generateTAC(expr, result);
    displayTAC();

    return 0;
}

