#include "push_swap.h"

int is_sorted(t_stack* stack)
{
    int min;

    if(stack->element_count < 2)
        return 1;
    min = stack->head->data;
    stack->head = stack->head->next;
    while(stack->head)
    {
        if(stack->head->data < min)
        {
            return 0;
        }
        min = stack->head->data;
        stack->head = stack->head->next;
    }
    return 1;
}
