// use *pNumber = (int*)malloc(25*sizeof(int)) instead of (int*)malloc(100) as we are sizes (int, float etc) differ based on system
// malloc returns a pointer of type pointer to void, so you have to cast.
// use NULL to check if malloc failed and returned a null pointer.
// use free() to release the memory for a block dynamically allocated whose address you have stored in pointer. free(pNumber)
// you can pass pointer of any type to free()

// calloc allocated memory as number of elements of a given size + initializes the memory to zero.
// int *pNumber = (int*)calloc(25, sizeof(int));

// realloc preserves the contents of the original memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = NULL;

    // initial memory allocation
    str = (char *)malloc(5); // since char is size 1. no need for *sizeof(char)
    strcpy(str, "afaq");
    printf("String: %s\n", str);
    printf("String Address: %p\n", (void *)str);

    // reallocating memory
    str = (char *)realloc(str, 25);
    strcat(str, " hamna");
    printf("String after realloc and strcat: %s\n", str);
    printf("String Address after realloc: %p\n", (void *)str);

    free(str);
}
