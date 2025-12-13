// A compact cheat sheet showing basic struct syntax, arrays of structs,
// nested structures, and simple usage patterns.
#include <stdio.h>

// Basic struct definition
struct Point {
    int x;
    int y;
};

// Typedef for shorter naming
typedef struct {
    char first[32];
    char last[32];
    int age;
} Person;

// Struct containing an array
typedef struct {
    char name[32];
    int scores[5];
} Player;

// Nested struct using previously defined types
typedef struct {
    struct Point top_left;
    struct Point bottom_right;
} Rectangle;

// More nested composition
typedef struct {
    char street[64];
    char city[32];
} Address;

typedef struct {
    Person person;   // embeds a Person
    Address address; // embeds an Address
} Record;

// Anonymous inner struct (C11 and later)
typedef struct {
    int id;
    struct {
        int day;
        int month;
        int year;
    } dob; // date of birth
} User;

static void demo_structs(void) {
    // Initialize structs
    struct Point p1 = { .x = 3, .y = 4 }; // designated init
    struct Point p2 = { 10, 20 };         // positional init
    p2.x = 15;                            // update a member

    printf("p1 = (%d, %d), p2 = (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

    // Array of structs
    Person people[3] = {
        { "Ana", "Lee", 25 },
        { "Bo",  "Kim", 28 },
        { "Cy",  "Ng",  22 },
    };
    people[1].age = 29; // update an element
    printf("Second person is now %d years old\n", people[1].age);

    // Struct containing an array
    Player player = { "Sam", { 10, 20, 30, 40, 50 } };
    printf("Player %s second score = %d\n", player.name, player.scores[1]);

    // Nested struct usage
    Rectangle rect = { { 0, 10 }, { 20, 0 } };
    int width = rect.bottom_right.x - rect.top_left.x;
    int height = rect.top_left.y - rect.bottom_right.y;
    printf("Rectangle width = %d, height = %d\n", width, height);

    // Nested with composition
    Record rec = {
        .person = { "Dana", "Quinn", 31 },
        .address = { "123 Main St", "Springfield" }
    };
    printf("%s %s lives in %s\n", rec.person.first, rec.person.last, rec.address.city);

    // Anonymous inner struct
    User user = { .id = 1, .dob = { 5, 6, 1990 } };
    printf("User %d birthday: %02d/%02d/%d\n", user.id, user.dob.day, user.dob.month, user.dob.year);
}

int main(void) {
    demo_structs();
    return 0;
}
