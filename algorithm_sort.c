#include "push_swap.h"

void sort_three(t_stack* stack) {
    int first = stack->head->data;
    int second = stack->head->next->data;
    int third = stack->head->next->next->data;

    if (first > second && second < third && first < third) {
        swap(stack);
        printf("sa\n");
    } else if (first > second && second > third && first > third) {
        swap(stack);
        printf("sa\n");
        reverse_rotate(stack);
        printf("rra\n");
    } else if (first > second && second < third && first > third) {
        rotate(stack);
        printf("ra\n");
    } else if (first < second && second > third && first < third) {
        swap(stack);
        printf("sa\n");
        rotate(stack);
        printf("ra\n");
    } else if (first < second && second > third && first > third) {
        reverse_rotate(stack);
        printf("rra\n");
    }
}
