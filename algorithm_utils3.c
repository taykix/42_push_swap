#include "push_swap.h"

void economic_rotate(t_stack* stackA, t_stack* stackB)
{
    t_node* cheapest_node;

    cheapest_node = get_cheapest(stackA);

    if (cheapest_node->is_above_median && cheapest_node->target->is_above_median
        && cheapest_node->index != 0 && cheapest_node->target->index != 0)
    {
        rotate(stackA);
        set_indexes(stackA);
        rotate(stackB);
        set_indexes(stackB);
        printf("rr\n");
    } else if (!cheapest_node->is_above_median && !cheapest_node->target->is_above_median
               && cheapest_node->index != 0 && cheapest_node->target->index != 0)
    {
        reverse_rotate(stackA);
        set_indexes(stackA);
        reverse_rotate(stackB); 
        set_indexes(stackB);
        printf("rrr\n");
    }
}

void nodes_a_to_b(t_stack* stackA, t_stack* stackB)
{
    t_node* cheapest_node;

    cheapest_node = get_cheapest(stackA);
    economic_rotate(stackA, stackB);

    if (rotate_node_to_top(stackA, cheapest_node, 'a') && rotate_node_to_top(stackB, cheapest_node->target, 'b'))
    {
        push_to(stackB, stackA);
        printf("pa\n");
    } else
        printf("EROR with rotating cheapest to top pa\n");
}

void nodes_b_to_a(t_stack* stackA, t_stack* stackB)
{


    if (rotate_node_to_top(stackA, stackB->head->target, 'a'))
    {
        push_to(stackA, stackB);
        printf("pb\n");
    } else
        printf("EROR with rotating b's target to top\n");
}

void get_stack_ready(t_stack* stackA, t_stack* stackB, char stack_name)
{
    set_indexes(stackA);
    set_indexes(stackB);
    reset_cheapest(stackA);
    reset_cheapest(stackB);

    if (stack_name == 'a')
    {
        set_target_a(stackA, stackB);
        cost_analysis_a(stackA, stackB);
        set_cheapest(stackA);
    } else if (stack_name == 'b')
    {
        set_target_b(stackB, stackA);
    }
}

void reset_cheapest(t_stack* stack){
    t_node* temp;

    temp = stack->head;
    while(temp)
    {
        temp->is_cheapest = 0;
        temp = temp->next;
    }
}

int rotate_node_to_top(t_stack* stack,t_node* node_for_top, char stack_name)
{
    t_node* node;

    node = node_for_top;

    while (node->index != 0)
    {
        if (node->is_above_median)
        {
            rotate(stack);
            printf("r");
        } else
        {
            reverse_rotate(stack);
            printf("rr");
        }
        printf("%c\n", stack_name);
        set_indexes(stack);
    }
    if (node->index == 0)
            return 1;
    else
        return 0;
}