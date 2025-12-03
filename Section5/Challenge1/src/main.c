#include <stdio.h>

int main() {
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
    char newLine = '\n';
    
    enum Company Company1 = XEROX;
    enum Company Company2 = GOOGLE;
    enum Company Company3 = EBAY;

    printf("%d%c%d%c%d%c", Company1, newLine, Company2, newLine, Company3, newLine);

    return 0;
}