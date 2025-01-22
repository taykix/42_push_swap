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

void print_stack(t_stack* stack) {
    t_node* temp = stack->head;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total elements: %d\n", stack->element_count);
}

void print_current_state(t_stack* stackA, t_stack* stackB) {
    printf("Stack A contents:\n");
    t_node* tempA = stackA->head;
    while (tempA != NULL) {
        printf("Index: %d, Value: %d, is_above_median: %d, Target Index: %d, Target Value: %d\n", 
               tempA->index, tempA->data, tempA->is_above_median, 
               tempA->target ? tempA->target->index : -1, 
               tempA->target ? tempA->target->data : -1);
        tempA = tempA->next;
    }
    printf("Total elements in Stack A: %d\n\n", stackA->element_count);

    printf("Stack B contents:\n");
    t_node* tempB = stackB->head;
    while (tempB != NULL) {
        printf("Index: %d, Value: %d, is_above_median: %d, Target Index: %d, Target Value: %d\n", 
               tempB->index, tempB->data, tempB->is_above_median, 
               tempB->target ? tempB->target->index : -1, 
               tempB->target ? tempB->target->data : -1);
        tempB = tempB->next;
    }
    printf("Total elements in Stack B: %d\n", stackB->element_count);
}
