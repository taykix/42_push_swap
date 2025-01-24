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
    struct Node* target;
    int index;
    int is_above_median;
    int is_cheapest;
    int push_cost;
} t_node;

// Stack structure
typedef struct Stack {
    t_node* head;
    t_node* tail;
    int element_count;
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
void print_current_state(t_stack* stackA, t_stack* stackB);
void sort_three(t_stack* stack);
void set_indexes(t_stack* stack);
void set_target_a(t_stack* stackA, t_stack* stackB);
void set_target_b(t_stack* stackB, t_stack* stackA);
t_node* find_max(t_stack* stack);
t_node* find_min(t_stack* stack);
void cost_analysis_a(t_stack* stackA, t_stack* stackB);
void set_cheapest(t_stack* stack);
void reset_cheapest(t_stack* stack);
t_node* get_cheapest(t_stack* stack);
void economic_rotate(t_stack* stackA, t_stack* stackB);
int rotate_node_to_top(t_stack* stack,t_node* node, char stack_name);
void get_stack_ready(t_stack* stackA, t_stack* stackB, char stack_name);
void nodes_a_to_b(t_stack* stackA, t_stack* stackB);
void nodes_b_to_a(t_stack* stackA, t_stack* stackB);
void sort_big(t_stack* stackA, t_stack* stackB);

#endif
