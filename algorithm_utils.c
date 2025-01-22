#include "push_swap.h"

int   is_sorted(t_stack* stack)
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

void set_indexes(t_stack* stack)
{
    t_node* temp;
    int index;
    int median;
    temp = stack->head;
    index = 0;
    median = stack->element_count / 2;

    while (temp != NULL) {
        temp->index = index;
        if (index <= median) {
            temp->is_above_median = 1;
        } else {
            temp->is_above_median = 0;
        }
        temp = temp->next;
        index++;
    }
}

void set_target_a(t_stack* stackA, t_stack* stackB)
{
    t_node* tempA;
    t_node* tempB;
    t_node* target;
    long     best_match;

    tempA = stackA->head;
    while(tempA)
    {
        tempB = stackB->head;
        best_match = LONG_MIN;
        while(tempB)
        {
            if(tempB->data < tempA->data && tempB->data > best_match)
            {
                best_match = tempB->data;
                target = tempB;
            }
            tempB = tempB->next;
        }
        if (best_match == LONG_MIN)
            tempA->target = find_max(stackB);
        else
            tempA->target = target;
        tempA = tempA->next;
    }
}

t_node* find_max(t_stack* stack)
{
    t_node* temp;
    t_node* max;

    temp = stack->head;
    max = temp;
    while(temp)
    {
        if(temp->data > max->data)
            max = temp;
        temp = temp->next;
    }
    return max;
}