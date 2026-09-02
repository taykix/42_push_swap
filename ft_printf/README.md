*This project has been created as part of the 42 curriculum by takaraka.*

# ft_printf

A rewrite of C's `printf` from scratch, built for the 42 curriculum.

## Description

`ft_printf` reads a format string, pulls the matching variadic arguments, converts them to text, writes them to standard output, and returns the number of characters printed.

Allowed functions and macros: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`. Everything else — string handling, number and hex conversion, pointer formatting — is written by hand.

Prototype:

```c
int ft_printf(const char *format, ...);
```

Supported conversions: `%c %s %p %d %i %u %x %X %%`. Flags, width and precision (bonus) are not implemented.

## Instructions

```bash
make        # builds libftprintf.a
make clean  # remove object files
make fclean # remove objects and the library
make re     # rebuild
```

Use it in your own code:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d\n", "world", 42);
    return (0);
}
```

Then link against the library:

```bash
cc main.c -L. -lftprintf -o program
```

## Algorithm and Data Structure

The program walks the format string once, character by character. Anything that isn't `%` is written straight out. On a `%`, the next character is read as the specifier and handed to the helper for that type, which pulls its argument with `va_arg`, converts it, prints it, and reports how many characters it wrote. A running counter holds the total and becomes the return value.

Since only the mandatory conversions are supported, there is nothing to carry between the `%` and the specifier, so no struct is needed — the only state is the position in the format string and the character count. If the bonus were added, a small struct holding the parsed flags, width and precision would sit between the `%` and the specifier; the mandatory part doesn't need it.

## Resources

- `man 3 printf` — to match the real function's output exactly.
- `man 3 stdarg` — the `va_*` macros.
- C99 standard, §7.19.6.1 — the formal spec for `printf`.

**Use of AI:** I used AI as a tutor to understand how variadic functions work under the hood (`stdarg.h`, how `va_list` moves through arguments in memory) and to work out the libft-to-Makefile linking (static archives, `-I`/`-L`/`-l`, recursive `make`). The parsing and conversion code is my own.

## Status

Completed at 42 Wolfsburg.