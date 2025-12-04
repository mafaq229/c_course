#include <stdio.h>

int main() {
    int minutes = 0;
    printf("Enter the number of minutes: ");
    scanf("%d", &minutes);

    printf("User entered: %d minutes\n", minutes);
    int minutesInYear = 365 * 24 * 60;
    int years = minutes / minutesInYear;
    float days = (minutes % minutesInYear) / (24.0 * 60.0); // atleast one operand (denominator in this case) should be float to avoid integer truncation
    
    printf("%d minutes is approximately %d years and %.2f days.\n", minutes, years, days);

    return 0;
}