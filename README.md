# push_swap

`push_swap` is a sorting algorithm project from the 42 curriculum.  
The goal of the project is to sort a stack of integers using only a limited set of stack operations and to output the shortest or most efficient sequence of instructions possible.

The project was developed under 42 constraints, using a restricted set of allowed external functions and manually implemented helper functions where needed.

## About the Project

In this project, I implemented a program that receives a list of integers as arguments, validates the input, and sorts the numbers using two stacks: stack `a` and stack `b`.

The program does not directly sort the array with standard sorting functions. Instead, it must use only the allowed stack operations such as swapping, pushing, rotating, and reverse rotating.

The main challenge of the project is not only to sort the numbers correctly, but also to reduce the number of operations as much as possible.

## Allowed Operations

The program can use the following operations:

### Swap

- `sa` — swap the first two elements of stack `a`
- `sb` — swap the first two elements of stack `b`
- `ss` — perform `sa` and `sb` at the same time

### Push

- `pa` — push the top element from stack `b` to stack `a`
- `pb` — push the top element from stack `a` to stack `b`

### Rotate

- `ra` — rotate stack `a` upwards
- `rb` — rotate stack `b` upwards
- `rr` — perform `ra` and `rb` at the same time

### Reverse Rotate

- `rra` — rotate stack `a` downwards
- `rrb` — rotate stack `b` downwards
- `rrr` — perform `rra` and `rrb` at the same time

## What I Implemented

- Input parsing and validation
- Duplicate number detection
- Integer overflow and invalid input handling
- Stack initialization and management
- Sorting logic using two stacks
- Operation execution and output
- Error handling
- Memory management and cleanup
- Helper functions for stack operations and algorithm logic

## What I Learned

- Working with stack data structures
- Designing sorting logic under strict operation constraints
- Handling edge cases and invalid input
- Managing dynamic memory in C
- Writing modular and maintainable C code
- Optimizing algorithmic steps
- Debugging and testing sorting behavior
- Following the 42 coding standard with Norminette

## Technologies Used

- C
- Makefile
- Git
- Norminette

## Build

To compile the project, run:

```bash
make
```

This creates the executable:

```bash
push_swap
```

Other available commands:

```bash
make clean
make fclean
make re
```

## Usage

Run the program with a list of integers:

```bash
./push_swap 3 2 1
```

Example output:

```text
sa
rra
```

The output is the list of operations needed to sort the stack.

## Input Rules

The program must handle:

- Positive and negative integers
- Already sorted input
- Reverse sorted input
- Duplicate numbers
- Invalid characters
- Integer overflow and underflow
- Empty input

Invalid input should print:

```text
Error
```

## Project Status

Completed as part of the 42 Wolfsburg curriculum.
