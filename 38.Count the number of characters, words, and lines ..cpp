#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, words = 0, lines = 0;
    bool inWord = false;

    // Prompt user for file name
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Count words
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            words++;
        }
    }

    // Close the file
    fclose(file);

    // If the last character isn't a newline, account for the last line
    if (characters > 0 && ch != '\n') {
        lines++;
    }

    // Display the counts
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
