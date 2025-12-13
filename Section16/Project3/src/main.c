#include <stdio.h>
#include <stdlib.h>

struct date {
    int month;
    int day;
    int year;
};

int main() {
    struct date today, *datePtr;
    datePtr = &today;

    datePtr->month = 9;
    datePtr->day = 25;
    datePtr->year = 2024;

    printf("Today's date is %d/%d/%d.\n", datePtr->month, datePtr->day, datePtr->year);

    // also the syntax
    (*datePtr).month = 10;
    (*datePtr).day = 20;
    (*datePtr).year = 2025;

    printf("Today's date is %d/%d/%d.\n", (*datePtr).month, (*datePtr).day, (*datePtr).year);

    return 0;
    
}
