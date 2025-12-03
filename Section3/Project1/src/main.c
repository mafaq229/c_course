#include <stdio.h>

int main(int argc, char **argv) {
    int myFavouriteNumber = 0;

    printf("Please enter your favourite number\n");
    scanf("%d", &myFavouriteNumber);
    printf("Your favourite number is %d\n", myFavouriteNumber);

    return 0;
}