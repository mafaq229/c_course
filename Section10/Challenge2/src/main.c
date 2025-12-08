#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char str[100];
    char name[25][50], temp[50];
    int l = 0, i = 0, n = 0, j = 0;

    printf("Print individual characters of a string in reverse order!\n");
    printf("----------------------------------------------\n");
    printf("Input the string: ");
    scanf("%s", str);
    // printf("String: %s\n", str);
    l = strlen(str);

    printf("The characters in reverse order are: \n");
    for (i = l; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    printf("----------------------------------------------\n");

    printf("Sorts the string of the array in bubble sort!\n");
    printf("----------------------------------------------\n");

    printf("Input the number of strings: ");
    scanf("%d", &n);

    printf("Input string %d: \n", n);

    for (i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }

    printf("The strings in sorted order are: \n");
    for (i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }

    return 0;
}