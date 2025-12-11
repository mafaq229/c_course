#include <stdio.h>
#include <string.h>


int main() {
    int i;
    long multiple[] = {15L, 25L, 35L, 45L};
    long *p = multiple;

    for (i = 0; i < sizeof(multiple) / sizeof(multiple[0]); i++) {
        // (p + i) is the address of multiple[i]; casting to unsigned long long and printing
        // with %llu shows the raw pointer value instead of the array element.
        printf("address p+%d (&multiple[%d]): %llu\n*(p+%d) value: %ld\n\n", i, i, (unsigned long long)(p+i), i, *(p+i));
    }
    printf("\n Type long occupies: %d bytes\n", (int)sizeof(long));
}
