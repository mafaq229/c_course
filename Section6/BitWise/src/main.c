#include <stdio.h>

int main() {

    unsigned int a = 60;  // 0011 1100
    unsigned int b = 13;  // 0000 1101
    int result = 0;
    printf("a = %d, b = %d\n", a,  b);

    result = a & b;           // AND  0000 1100 = 12
    printf("a & b = %d\n", result);

    result = a | b;           // OR   0011 1101 = 61
    printf("a | b = %d\n", result);

    result = a ^ b;           // XOR  0011 0001 = 49
    printf("a ^ b = %d\n", result);

    result = ~a;              // NOT  1100 0011 = -61
    printf("~a = %d\n", result);

    result = a << 2;         // Left Shift  1111 0000 = 240
    printf("a << 2 = %d\n", result);
    result = a >> 2;         // Right Shift  0000 1111 = 15
    printf("a >> 2 = %d\n", result);

    result = b << 2;         // Left Shift  0011 0100 = 52
    printf("b << 2 = %d\n", result);
    result = b >> 2;         // Right Shift  0000 0011 = 3
    printf("b >> 2 = %d\n", result);

    result = a << 1;         // Left Shift  0111 1000 = 120
    printf("a << 1 = %d\n", result);

    result = b >> 3;         // Right Shift  0000 0001 = 1
    printf("b >> 3 = %d\n", result);

    return 0;
}