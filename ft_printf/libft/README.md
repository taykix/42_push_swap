This project has been created as part of the 42 curriculum by [takaraka].
# Libft

## Description

Libft is a foundational project from the 42 curriculum focused on building a custom C library from scratch.
The goal of the project is to reimplement essential standard C library functions and create additional utility functions that can be reused in future C projects.

## Instructions

### Requirements

- A Unix-like environment (Linux or macOS)
- `gcc` (or another C compiler)
- `make`
- `ar` (usually shipped with `binutils`)

### Build

To compile the library, run:

```bash
make
```

This creates the static library:

```bash
libft.a
```

Other available commands:

```bash
make clean
make fclean
make re
```

### Usage

Include the header file in your C project:

```c
#include "libft.h"
```

Compile your project together with the library:

```bash
cc main.c -L. -lft
```
## Library Description

The library is organized into three parts.

### Part 1 -- Libc functions

Reimplementations of standard C library functions, prefixed with `ft_`:

| Function | Purpose |
|----------|---------|
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character classification. |
| `ft_strlen` | Returns the length of a string. |
| `ft_memset`, `ft_bzero` | Fill a memory block with a byte value / with zeros. |
| `ft_memcpy`, `ft_memmove` | Copy memory blocks (`memmove` is overlap-safe). |
| `ft_strlcpy`, `ft_strlcat` | Size-bounded string copy and concatenation. |
| `ft_toupper`, `ft_tolower` | Case conversion of a single character. |
| `ft_strchr`, `ft_strrchr` | Locate the first / last occurrence of a character in a string. |
| `ft_strncmp` | Compare two strings up to *n* bytes. |
| `ft_memchr` | Locate a byte in a memory block of a given size. |
| `ft_memcmp` | Compare two memory blocks. |
| `ft_strnstr` | Locate a substring within a bounded string. |
| `ft_atoi` | Convert a string to an integer. |
| `ft_calloc` | Allocate and zero-initialize memory. |
| `ft_strdup` | Duplicate a string into newly allocated memory. |

### Part 2 -- Additional functions

Utility functions not present (in this exact form) in the standard library:

| Function | Purpose |
|----------|---------|
| `ft_substr` | Extract a substring from a string. |
| `ft_strjoin` | Concatenate two strings into a newly allocated one. |
| `ft_strtrim` | Trim a set of characters from both ends of a string. |
| `ft_split` | Split a string into an array of substrings by a delimiter. |
| `ft_itoa` | Convert an integer to its string representation. |
| `ft_strmapi` | Apply a function to each character of a string, producing a new string. |
| `ft_striteri` | Apply a function to each character of a string, modifying it in place. |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a char / string / string+newline / number to a given file descriptor. |

### Part 3 -- Linked lists

A set of functions to create and manipulate a singly linked list, based on the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Purpose |
|----------|---------|
| `ft_lstnew` | Create a new list node from a content pointer. |
| `ft_lstadd_front` | Add a node at the beginning of the list. |
| `ft_lstadd_back` | Add a node at the end of the list. |
| `ft_lstsize` | Count the number of nodes in the list. |
| `ft_lstlast` | Return the last node of the list. |
| `ft_lstdelone` | Delete a single node, freeing its content with a given function. |
| `ft_lstclear` | Delete and free an entire list. |
| `ft_lstiter` | Apply a function to the content of each node. |
| `ft_lstmap` | Build a new list by applying a function to each node's content. |

## Resources

Classic references used while working on this project:

- **The C Programming Language** -- Brian W. Kernighan & Dennis M. Ritchie (K&R): the canonical reference for C.
- **man pages** -- the primary source for the exact behavior of each libc function (`man memset`, `man strlcpy`, `man atoi`, etc.).
- **42 subject PDF** -- the official project specification and function prototypes.
- **Makefile Tutorial** -- https://makefiletutorial.com/ to refresh my knowledge about Makefiles
### Use of AI

I used an AI assistant for generating this Read.md file. And also to get some quick information about Makefiles, purpose of .PHONY, ar rcs and the re rule. Also I used Claude web application to understand diffrence between memcpy and memmove.
