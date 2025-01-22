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
