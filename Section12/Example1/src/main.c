#include <stdio.h>

int main() {
    int *p = NULL;
    int *q = 0;

    if (p)
        printf(" p ");
    else
        printf("nullp");
    
    if (q)
        printf("q\n");
    else
        printf(" nullq\n");
}