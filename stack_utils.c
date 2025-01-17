#include "push_swap.h"

t_node* create_node(int data)
{
    t_node* newNode = (t_node*)malloc(sizeof(t_node));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void init_stack(t_stack* stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->element_count = 0;
}
int insert_before_head(t_stack* stack, int data)
{
    t_node* newNode = create_node(data);
    if (!newNode)
        return -1;

    if (stack->head == NULL) {
        stack->head = newNode;
        stack->tail = newNode;
    } else {
        newNode->next = stack->head;
        stack->head->prev = newNode;
        stack->head = newNode;
    }

    stack->element_count++;
    return 0;
}

int delete_head(t_stack* stack)
{
    if (stack->head == NULL)
        return -1;

    t_node* temp = stack->head;

    if (stack->head == stack->tail) {
        stack->head = NULL;
        stack->tail = NULL;
    } else {
        stack->head = stack->head->next;
        stack->head->prev = NULL;
    }

    free(temp);
    stack->element_count--;
    return 0;
}

int is_duplicate(t_stack* stack, int value)
{
    t_node* current = stack->head;
    while (current != NULL) {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}
