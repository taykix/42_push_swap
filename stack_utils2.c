#include "push_swap.h"

int is_empty(t_stack* stack)
{
    return stack->head == NULL;
}

void push(t_stack* stack, int data)
{
    if (is_duplicate(stack, data)) {
        printf("Error: Duplicate value detected (%d)\n", data);
        return;
    }

    if (insert_before_head(stack, data) == -1) {
        printf("Error: Memory allocation failed\n");
    }
}

int pop(t_stack* stack)
{
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped_value = stack->head->data;
    delete_head(stack);
    return popped_value;
}

void free_stack(t_stack* stack)
{
    while (!is_empty(stack)) {
        delete_head(stack);
    }
}


