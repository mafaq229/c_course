// fgets example:
// - fgets(char *buf, int size, FILE *stream) reads up to size-1 chars and NUL-terminates.
// - Good for line-based input; avoids overflow that gets/scanf("%s") can cause.
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char str[60] = {0}; // buffer sized for fgets; init ensures NUL fill if read fails
    
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error in opening file.");
        return 1;
    }

    // fgets returns NULL on error or EOF; on success buffer is NUL-terminated.
    if (fgets(str, (int)sizeof(str), fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);
    fp = NULL;
    return 0;
}
