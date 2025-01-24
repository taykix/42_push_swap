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

void sort_big(t_stack* stackA, t_stack* stackB) {
    
    if(stackA->element_count > 3 && !is_sorted(stackA))
    {
        push_to(stackB, stackA);
        printf("pb\n");
    }
    if(stackA->element_count > 3 && !is_sorted(stackA))
    {
        push_to(stackB, stackA);
        printf("pb\n");
    }
    while (stackA->element_count > 3 && !is_sorted(stackA))
    {
        get_stack_ready(stackA, stackB, 'a');
        nodes_a_to_b(stackA, stackB);
    }
    if (!is_sorted(stackA) && stackA->element_count == 3)
        sort_three(stackA);
    while (stackB->element_count > 0)
    {
        get_stack_ready(stackA, stackB, 'b');
        nodes_b_to_a(stackA, stackB);
    }
    set_indexes(stackA);
    rotate_node_to_top(stackA, find_min(stackA), 'a');
}
