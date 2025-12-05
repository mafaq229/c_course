#include <stdio.h>


int main() {
    unsigned long long sum = 0LL; // stores the sum of intergers
    unsigned int count = 0; // number of integers to be summed

    printf("Enter the number of integers to sum: ");
    scanf("%u", &count);

    for (unsigned int i = 1; i <= count; ++i) {
        sum += i;
    }

    printf("Total of the first %u integers is %llu\n", count, sum);

    int a = 0, i = 0;
    for (i = 0;i < 5; i++)
        {
            a++;
            if (i == 3)
                break;
        }

       printf("%d\n", a);

    return 0;
}