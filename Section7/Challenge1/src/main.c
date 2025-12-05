#include <stdio.h>

int main() {

    int hoursWorked;
    printf("Enter the number of hours worked in a week: ");
    scanf("%i", &hoursWorked);

    double basicPayRate = 12.0;
    double overtimePayRate = basicPayRate * 1.5;
    double taxRate1 = 0.15; // for first $300
    double taxRate2 = 0.20; // for next $150
    double taxRate3 = 0.25; // for the rest

    double grossPay = 0.0;
    if (hoursWorked > 40) {
        int overtimeHours = hoursWorked - 40;
        grossPay = (40 * basicPayRate) + (overtimeHours * overtimePayRate);
    }
    else {
        grossPay = hoursWorked * basicPayRate;
    }

    double taxes = 0.0;
    if (grossPay <= 300) {
        taxes = grossPay * taxRate1;
    }
    else if (grossPay <= 450) {
        taxes = (300 * taxRate1) + ((grossPay - 300) * taxRate2);
    }
    else if (grossPay > 450) {
        taxes = (300 * taxRate1) + (150 * taxRate2) + ((grossPay - 450) * taxRate3);
    }

    double netPay = grossPay - taxes;
    printf("Gross Pay: $%.2f\n", grossPay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", netPay);

    return 0;
}