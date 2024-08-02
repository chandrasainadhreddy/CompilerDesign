-#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_RULES 10

typedef struct {
    char nonTerminal;
    char productions[MAX_RULES][MAX];
    int productionCount;
} Grammar;

void eliminateLeftFactoring(Grammar *grammar) {
    for (int i = 0; i < grammar->productionCount - 1; i++) {
        for (int j = i + 1; j < grammar->productionCount; j++) {
            int k = 0;
            while (grammar->productions[i][k] == grammar->productions[j][k] && grammar->productions[i][k] != '\0') {
                k++;
            }
            if (k > 0) {
                char newNonTerminal = grammar->nonTerminal + 1;
                printf("%c -> %.*s%c\n", grammar->nonTerminal, k, grammar->productions[i], newNonTerminal);
                printf("%c -> %s\n", newNonTerminal, &grammar->productions[i][k]);
                printf("%c -> %s\n", newNonTerminal, &grammar->productions[j][k]);
                for (int m = 0; m < grammar->productionCount; m++) {
                    if (m != i && m != j) {
                        printf("%c -> %s\n", grammar->nonTerminal, grammar->productions[m]);
                    }
                }
                return;
            }
        }
    }
    printf("The provided grammar does not contain left factoring.\n");
}

int main() {
    Grammar grammar;
    char input[MAX];

    printf("Enter the non-terminal:\n");
    scanf(" %c", &grammar.nonTerminal);

    printf("Enter the productions (end with an empty line):\n");
    getchar(); 
    grammar.productionCount = 0;

    while (1) {
        fgets(input, MAX, stdin);
        if (input[0] == '\n') {
            break;
        }
        input[strcspn(input, "\n")] = 0; 
        strcpy(grammar.productions[grammar.productionCount++], input);
    }

    eliminateLeftFactoring(&grammar);

    return 0;
}
