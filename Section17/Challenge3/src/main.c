#include <stdio.h>
#include <stdlib.h>

// Reverse-print a file using random access.
// Function signatures of interest:
// - int fseek(FILE *stream, long offset, int origin): reposition file pointer relative to origin.
// - long ftell(FILE *stream): get current file position; useful to know file size when at end.
// - int fgetc(FILE *stream): read one byte at current position.

#define FILENAME "file.txt"

int main(void) {
    FILE *fp = NULL;

    long cnt = 0;
    long i = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Move to end to measure file length.
    fseek(fp, 0, SEEK_END);
    cnt = ftell(fp); // total bytes in file

    // Walk backward from end to beginning, printing characters in reverse order.
    while (i < cnt) {
        i++;
        fseek(fp, -i, SEEK_END); // negative offset moves backward from end
        printf("%c", fgetc(fp));
    }
    printf("\n");

    fclose(fp);
    fp = NULL;

    return 0;
}
