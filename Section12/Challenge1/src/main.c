#include <stdio.h>
#include <stdlib.h>


int main() {
    int number = 150;
    int *pnumber = NULL;

    printf("number's address: %p\n", &number);
    
    pnumber = &number;
    //printf("pnumber's address: %p\n", &pnumber);
    //printf("pnumber's size: %lu bytes\n", sizeof(pnumber));
    printf("pnumber's value: %p\n", pnumber);
    printf("number's value: %d\n", number);
    printf("value pointed to: %d\n", *pnumber);

    return 0;
}