#include <stdio.h>

//extern int x;
int x = 42;

int main(int argc, char **argv) {

    puts("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Your favourite number is %d\n", x);
    fputs("Using fputs to print without formatting or auto-newline\n", stdout);
    putchar('A');
    putchar('\n');
    fprintf(stdout, "fprintf writes to stdout too: %d\n", x);

    char buffer[64];
    int written = snprintf(buffer, sizeof(buffer), "snprintf into a buffer: %d", x);
    printf("Buffered string: %s (length %d)\n", buffer, written);

    return 0;
}
