#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Demo of structures and pointers: pointer-to-struct, pointer members,
// dynamic allocation, and pointer dereference (->).
//
// About typedef: using `typedef struct { ... } Person;` lets you write
// `Person` instead of `struct Person` when declaring variables. It's a
// convenience to reduce verbosity; the underlying type is still a struct.

typedef struct {
    char street[64];
    char city[32];
} Address;

typedef struct {
    char name[32];
    int age;
    Address *address; // pointer to another struct
} Person;

static Address *make_address(const char *street, const char *city) {
    Address *addr = malloc(sizeof(Address));
    if (!addr) {
        return NULL;
    }
    strncpy(addr->street, street, sizeof(addr->street) - 1);
    addr->street[sizeof(addr->street) - 1] = '\0';
    strncpy(addr->city, city, sizeof(addr->city) - 1);
    addr->city[sizeof(addr->city) - 1] = '\0';
    return addr;
}

static Person *make_person(const char *name, int age, Address *addr) {
    Person *p = malloc(sizeof(Person));
    if (!p) {
        return NULL;
    }
    strncpy(p->name, name, sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0';
    p->age = age;
    p->address = addr; // struct contains pointer member
    return p;
}

static void print_person(const Person *p) {
    // Use -> because p is a pointer; nested pointers use another ->
    printf("Name: %s, Age: %d\n", p->name, p->age);
    if (p->address) {
        printf("Address: %s, %s\n", p->address->street, p->address->city);
    } else {
        printf("Address: (none)\n");
    }
}

int main(void) {
    // Stack-allocated Address, Person uses pointer to it
    Address home = { "123 Main St", "Springfield" };
    Person alice = { "Alice", 30, &home };
    print_person(&alice); // pass pointer to struct

    // Without typedef you'd need the `struct` keyword each time:
    struct Address cabin = { "789 Lake Rd", "Lakeside" };
    struct Person clara = { "Clara", 27, &cabin };
    print_person(&clara);

    // Dynamically allocated Address and Person
    Address *office = make_address("456 Office Park", "Metropolis");
    Person *bob = make_person("Bob", 40, office);
    if (bob && office) {
        print_person(bob);
    } else {
        fprintf(stderr, "Allocation failed\n");
    }

    // Pointer-to-pointer: modify through pointer to struct
    if (bob) {
        Person *p = bob; // pointer to struct
        p->age += 1;     // update via ->
        print_person(p);
    }

    free(office);
    free(bob);
    return 0;
}
