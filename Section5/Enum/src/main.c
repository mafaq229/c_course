#include <stdio.h>

int main() {
    enum gender {male, female};
    enum gender myGender;

    myGender = male;

    // myGender = 33;
    printf("My gender is: %d\n", myGender);

    char myCharacter = '\n';
    printf("%c", myCharacter);

    return 0;
    
}
