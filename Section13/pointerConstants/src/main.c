#include <stdio.h>

int main() {
    int value = 10;
    int other = 20;
    int third = 30;

    // Pointer to const data: data read-only through the pointer; pointer itself can move.
    const int *ptr_to_const = &value;      // same as "int const *"
    printf("ptr_to_const -> %d\n", *ptr_to_const);
    // *ptr_to_const = 11;                 // would not compile: cannot modify through pointer
    ptr_to_const = &other;                 // re-pointing is fine
    printf("ptr_to_const moved -> %d\n", *ptr_to_const);
    other = 25;                            // data can still change via another alias
    printf("other updated -> %d (seen via ptr_to_const)\n", *ptr_to_const);

    // Const pointer to non-const data: pointer target fixed; data mutable.
    int *const const_ptr = &value;
    *const_ptr = 15;                       // ok: modifies value
    printf("const_ptr -> %d\n", *const_ptr);
    // const_ptr = &other;                 // would not compile: pointer itself is const

    // Const pointer to const data: neither the pointer nor the data can change through it.
    const int *const fully_const = &third;
    printf("fully_const -> %d\n", *fully_const);
    // *fully_const = 35;                  // error: data read-only
    // fully_const = &value;               // error: pointer read-only

    // Top-level const (not via pointer): the variable itself is immutable.
    const int fixed = 40;                  // must be initialized
    // fixed = 41;                         // would not compile
    const int *ref_fixed = &fixed;         // safe to point at const data
    printf("fixed via ref_fixed -> %d\n", *ref_fixed);

    // Mixing const placement for clarity: both lines mean "pointer to const int".
    int const *also_ptr_to_const = &value;
    printf("also_ptr_to_const -> %d\n", *also_ptr_to_const);

    // Mutable pointer to mutable data (baseline for comparison).
    int *plain_ptr = &value;
    *plain_ptr = 50;
    plain_ptr = &other;
    printf("plain_ptr now -> %d\n", *plain_ptr);

    return 0;
}
