#include <stdio.h>
#include <stdlib.h>

int getGreatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getAbsoluteValue(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double square_root(int x) {
    if (x < 0) {
        printf("Error: Negative input to sqrt\n");
        return -1;
    }
    else if (x == 0) {
        return 0;
    }
    const double eps = 0.000001;

    // initial guess can be half of x or 1.0
    double guess = 1.0;

    // iterate until guess^2 is close enough to x
    while (getAbsoluteValue(guess * guess - x) > eps) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}



int main() {
    printf("Greatest Common Divisor between 25 and 15 is %d\n", getGreatestCommonDivisor(25, 15));
    printf("Absolute value of -10 is %d\n", getAbsoluteValue(-10));
    printf("Square root of 16 is %f\n", square_root(16));
    printf("Square root of 10 is %f\n", square_root(10));

    return 0;
}