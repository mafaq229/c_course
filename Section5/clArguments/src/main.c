#include <stdio.h>
#include "test.h"

// argc is argument count
// argv is argument vector (array of strings)
int main(int argc, char *argv[]) {
    int numberOfArguments = argc;
    char *argument1 = argv[0];
    char *argument2 = argv[1];

    printf("Number of arguments: %d\n", numberOfArguments);
    printf("Argument 1 is the program name: %s\n", argument1);
    printf("Argument 2 is the command line argument: %s\n", argument2);
    
    print_args(argc, argv);
    
    return 0;
}