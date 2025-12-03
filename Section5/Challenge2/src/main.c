#include <stdio.h>

int main(int argc, char *argv[]) {
    double width = 3.34;
    double height = 5.56;

    double area = 0.0;
    double perimeter = 2 * (width + height);

    area = width * height;

    printf("Width: %f\n", width);
    printf("Height: %f\n", height);
    printf("Area: %f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    
    return 0;
}