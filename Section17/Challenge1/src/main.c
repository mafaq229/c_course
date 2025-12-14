#include <stdio.h>
#include <stdlib.h>

// Counts lines by scanning for newline characters.
// Useful function signatures:
// - int fgetc(FILE *stream): returns next unsigned char (promoted to int) or EOF.
// - FILE *fopen(const char *path, const char *mode): returns pointer or NULL on failure.
// - int fclose(FILE *stream): returns 0 on success; always call when done.

#define FILENAME "file.txt"

int main(void) {
    FILE *fp = NULL;
    char ch;
    int linesCount = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error in opening file.");
        return 1;
    }

    // Loop until EOF; count newline characters to approximate line count.
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linesCount++;
        }
    }

    fclose(fp);
    fp = NULL;

    printf("Number of lines: %d\n", ++linesCount); // add last line if file doesn't end with '\n'

    return 0;
}
