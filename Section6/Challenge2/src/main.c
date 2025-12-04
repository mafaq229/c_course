#include <stdio.h>

int main() {

    // %zu bytes is the format specifier for size_t type (unsigned)
    printf("int size: %zu bytes\n", sizeof(int));
    printf("float size: %zu bytes\n", sizeof(float));
    printf("double size: %zu bytes\n", sizeof(double));

    printf("char size: %zu bytes\n", sizeof(char));
    printf("short size: %zu bytes\n", sizeof(short));
    printf("long size: %zu bytes\n", sizeof(long));
    printf("long long size: %zu bytes\n", sizeof(long long));

    printf("long double size: %zu bytes\n\n", sizeof(long double));

    // %zd bytes is the format specifier for ssize_t type (signed counterpart of size_t)
    printf("int size: %zd bytes\n", sizeof(int));
    printf("float size: %zd bytes\n", sizeof(float));
    printf("double size: %zd bytes\n", sizeof(double));

    printf("char size: %zd bytes\n", sizeof(char));
    printf("short size: %zd bytes\n", sizeof(short));
    printf("long size: %zd bytes\n", sizeof(long));
    printf("long long size: %zd bytes\n", sizeof(long long));

    printf("long double size: %zd bytes\n", sizeof(long double));

    short int i = 20;
    char c = 97;
    printf("%d, %d, %d\n", sizeof(i), sizeof(c), sizeof(c + i));
    return 0;

    return 0;
}