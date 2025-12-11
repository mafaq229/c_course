#include <stdio.h>

void square(int *const x);

int main() {
    int num;
    printf("Enter a number to get its square: ");
    scanf("%d", &num);
    square(&num);
    printf("The square of the given number is; %d\n", num);
    return 0;
}

void square(int *const x) { // fixing the address. data mutable
    *x = (*x) * (*x);
}