#include <stdio.h>

// Note: in parameters, "int array[]" is identical to "int *array" because arrays
// decay to pointers when passed to functions; the function receives a pointer to
// the first element, not the whole array object.
int arraySum(int array[], const int n) {
    int sum = 0, *ptr;
    int *const arrayEnd = array + n;

    for (ptr = array; ptr < arrayEnd; ptr++) { // also &array[0]
        sum += *ptr;
    }
    return sum;
}

int main() {
    //int arraySum (int array[], const int n); // function decleration (no need since it is declared at the top)
    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum(values, 10));
}
