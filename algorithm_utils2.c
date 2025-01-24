#include "push_swap.h"

void set_cheapest(t_stack* stack)
{
	t_node* temp;
	t_node* cheapest_node;
	long     cheapest_value;

	if(!stack)
		return;
	temp = stack->head;
	cheapest_value = LONG_MAX;
	while(temp)
	{
		if (temp->push_cost < cheapest_value)
		{
			cheapest_value = temp->push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->is_cheapest = 1;
}

t_node* get_cheapest(t_stack* stack)
{
	t_node* temp;

	if(!stack)
		return NULL;
	temp = stack->head;
	while(temp)
	{
		if (temp->is_cheapest)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void set_target_b(t_stack* stackB, t_stack* stackA)
{
    t_node* tempA;
    t_node* tempB;
    t_node* target;
    long     best_match;

    tempB = stackB->head;
    while(tempB)
    {
        tempA = stackA->head;
        best_match = LONG_MAX;
        while(tempA)
        {
            if(tempA->data > tempB->data && tempA->data < best_match) //closeset bigest
            {
                best_match = tempA->data;
                target = tempA;
            }
            tempA = tempA->next;
        }
        if (best_match == LONG_MAX)
            tempB->target = find_min(stackA);
        else
            tempB->target = target;
        tempB = tempB->next;
    }
}

t_node* find_min(t_stack* stack)
{
    t_node* temp;
    t_node* min;

    temp = stack->head;
    min = temp;
    while(temp)
    {
        if(temp->data < min->data)
            min = temp;
        temp = temp->next;
    }
    return min;
}
