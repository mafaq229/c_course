#include <stdio.h>

struct employee {
    char name[50];
    char hireDate[15];
    float salary; 
};

int main() {
    // declare and initialization
    struct employee emp = {"John Doe", "2023-01-15", 50000.00f};

    printf("Employee Name: %s\n", emp.name);
    printf("Hire Date: %s\n", emp.hireDate);
    printf("Salary: %.2f\n", emp.salary);

    printf("Enter employee information: \n");
    printf("Name: ");
    scanf("%s", emp.name);
    printf("Hire Date: ");
    scanf("%s", emp.hireDate);
    printf("Salary: ");
    scanf("%f", &emp.salary);

    printf("Employee Name: %s\n", emp.name);
    printf("Hire Date: %s\n", emp.hireDate);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}