#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Double-linked node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} t_node;

// Stack structure
typedef struct Stack {
    t_node* head; // Pointer to the top of the stack
    t_node* tail; // Pointer to the bottom of the stack
    int element_count; // Number of elements in the stack
} t_stack;

// Function prototypes
t_node* create_node(int data);
void init_stack(t_stack* stack);
int insert_before_head(t_stack* stack, int data);
int is_empty(t_stack* stack);
void push(t_stack* stack, int data);
int pop(t_stack* stack);
void print_stack(t_stack* stack);
int validate_and_convert(const char* arg);
int is_duplicate(t_stack* stack, int value);
void free_stack(t_stack* stack);
void swap(t_stack* stack);
void push_to(t_stack* dest, t_stack* src);
void rotate(t_stack* stack);
void reverse_rotate(t_stack* stack);
int delete_head(t_stack* stack);
int is_sorted(t_stack* stack);

#endif