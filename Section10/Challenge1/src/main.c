#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int stringLength(const char string[]);
void concat(char result[], const char str1[], const char str2[]);
bool equalStrings(const char str1[], const char str2[]);


int main() {
    printf("String Length of '%s' is %d\n", "Im tired!!!", stringLength("Im tired!!!"));
    
    char result[50];
    concat(result, "Hello, ", "world!");
    printf("Concatenated string: %s\n", result);
    printf("Concatenated string length: %d\n", stringLength(result));
    printf("Are the strings equal? %s\n", equalStrings("Hello, world!", result) ? "Yes" : "No");
    printf("Are the strings equal? %d\n", equalStrings("Hi, world!", result));

    return 0;
}

int stringLength(const char string[]) {
    int count = 0;
    while (string[count] != '\0') {
        count++;
    }
    return count;
}

void concat(char result[], const char str1[], const char str2[]) {
    int i, j;

    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';
}

bool equalStrings(const char str1[], const char str2[]) {
    int i = 0;
    bool isEqual = false;

    while ( str1[i] == str2[i] && 
            str1[i] != '\0' && 
            str2[i] != '\0') {
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        isEqual = true;
    }
    else {
        isEqual = false;
    }
    return isEqual;
}
