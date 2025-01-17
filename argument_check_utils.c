#include "push_swap.h"

int validate_and_convert(const char* arg) {
    char* endptr;
    long value = strtol(arg, &endptr, 10);

    if (*endptr != '\0') {
        fprintf(stderr, "Error: '%s' is not a valid integer\n", arg);
        exit(EXIT_FAILURE);
    }

    if (value < INT_MIN || value > INT_MAX) {
        fprintf(stderr, "Error: '%s' is out of range for an integer\n", arg);
        exit(EXIT_FAILURE);
    }

    return (int)value;
}

void print_current_state(t_stack* stackA, t_stack* stackB) {
    printf("Stack A contents: \n");
    print_stack(stackA);
    printf("Stack B contents: \n");
    print_stack(stackB);
}
