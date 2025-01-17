#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <integers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    t_stack stackA;
    t_stack stackB;

    init_stack(&stackA);
    init_stack(&stackB);

    i = 1;
    while (i < argc) {
        int value = validate_and_convert(argv[i]);
        if (!is_duplicate(&stackA, value)) {
            push(&stackA, value);
        } else {
            fprintf(stderr, "Error: Duplicate value detected (%d)\n", value);
            free_stack(&stackA);
            free_stack(&stackB);
            return EXIT_FAILURE;
        }
        i++;
    }

    printf("Stack A contents: \n");
    print_stack(&stackA);

    // Example operations
    if(is_sorted(&stackA))
    {
        printf("Stack is sorted\n");
    } else
        printf("Stack is not sorted\n");

    // Free both stacks
    free_stack(&stackA);

    return EXIT_SUCCESS;
}
