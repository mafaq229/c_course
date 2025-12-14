#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // islower(int c), toupper(int c) and other character classification helpers

// Task: read a file, uppercase lowercase letters, write to temp, then replace original.
// Function signatures highlighted:
// - int islower(int c): expects unsigned-char value or EOF; returns nonzero if lowercase.
// - int fputc(int ch, FILE *stream): writes a byte (converted to unsigned char) and returns it or EOF.
// - int rename(const char *old, const char *new): renames/moves a file.
// - int remove(const char *path): deletes a file; here used to clean up if rename already replaced it.

#define FILENAME "file.txt"

int main(void) {
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = 'a'; // seed value; immediately overwritten by fgetc

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening input file");
        return -1;
    }

    fp1 = fopen("temp.txt", "w");
    if (fp1 == NULL) {
        perror("Error opening temp file");
        fclose(fp);
        return -1;
    }

    // Transform stream: uppercase if lowercase, write to temp.
    while ((ch = (char)fgetc(fp)) != EOF) {
        if (islower((unsigned char)ch)) {
            ch = (char)(ch - 32); // manual toupper for illustration
        }
        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    // Replace the original with the temp content.
    rename("temp.txt", FILENAME);
    remove("temp.txt"); // harmless if rename succeeded; cleanup otherwise

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error reopening file");
        return -1;
    }

    // Show the resulting file
    while ((ch = (char)fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
    fp = NULL;
    fp1 = NULL;

    return 0;
}
