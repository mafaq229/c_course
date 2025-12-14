// Basic file read example:
// - FILE * is an opaque handle returned by fopen(const char *path, const char *mode).
// - fgetc(FILE *) reads one byte/char at a time, returning int so EOF (-1) is representable.
// - fclose(FILE *) releases the handle; always set your pointer to NULL after closing to avoid dangling references.
#include <stdio.h>

int main(void) {
    FILE *fp = NULL; // file handle pointer
    int c;           // int (not char) to hold fgetc result including EOF

    fp = fopen("file.txt", "r"); // "r" = read mode
    if (fp == NULL) {
        perror("Error in opening file."); // perror uses errno to print system error string
        return 1;
    }

    // fgetc returns unsigned char cast to int, or EOF on end/error.
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
    fp = NULL;
    return 0;
}
