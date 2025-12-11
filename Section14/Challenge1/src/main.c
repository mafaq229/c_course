#include <stdio.h>
#include <string.h>

int stringLen(const char *string) {
    const char *lastAddress = string;
    while (*lastAddress) {
        lastAddress++;
    }
    return lastAddress - string;
}

int main() {
    char myString[] = "Hi!!!";
    int length = stringLen(myString);
    printf("Length of the string: %d\n", length);
    printf("Length of the string (inbuilt): %zu\n", strlen(myString));
}
