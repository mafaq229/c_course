#include <stdio.h>

int main() {
    // Array of pointers to individual ints.
    int a = 10, b = 20, c = 30;
    int *int_ptrs[3] = { &a, &b, &c };   // "array of int pointers"

    printf("Array of pointers (int_ptrs):\n");
    for (int i = 0; i < 3; ++i) {
        printf("  int_ptrs[%d] points to %p with value %d\n", i, (void *)int_ptrs[i], *int_ptrs[i]);
    }

    // Changing data through the array of pointers.
    *int_ptrs[1] = 25;   // modifies b through pointer
    printf("After *int_ptrs[1] = 25 -> b = %d\n\n", b);

    // Pointer to an entire array: note the parentheses.
    int numbers[3] = { 1, 2, 3 };
    int (*ptr_to_array)[3] = &numbers;   // "pointer to array of 3 ints"

    printf("Pointer to array (ptr_to_array):\n");
    printf("  ptr_to_array address: %p\n", (void *)ptr_to_array);
    printf("  first element via (*ptr_to_array)[0] = %d\n", (*ptr_to_array)[0]);
    (*ptr_to_array)[2] = 99;  // modifies numbers[2]
    printf("  after change, numbers[2] = %d\n\n", numbers[2]);

    // Pointer arithmetic: ptr_to_array + 1 jumps by the size of the whole array (3 ints).
    int matrix[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    int (*row_ptr)[3] = matrix;   // decays to pointer to first row (array of 3 ints)
    printf("Pointer arithmetic on pointer-to-array:\n");
    printf("  row_ptr = %p -> first row first elem = %d\n", (void *)row_ptr, row_ptr[0][0]);
    printf("  row_ptr + 1 = %p -> second row first elem = %d\n\n", (void *)(row_ptr + 1), row_ptr[1][0]);

    // Array of pointers to string literals (common pattern for command-line args).
    const char *colors[] = { "red", "green", "blue", "yellow" };
    size_t color_count = sizeof(colors) / sizeof(colors[0]);
    printf("Array of const char* (colors):\n");
    for (size_t i = 0; i < color_count; ++i) {
        printf("  colors[%zu] -> \"%s\"\n", i, colors[i]);
    }

    // Compare declarations:
    //   int *p[3];      -> array of 3 pointers to int
    //   int (*p)[3];    -> pointer to an array of 3 int
    // Parentheses change the binding; without them, [] binds tighter than *.

    return 0;
}
