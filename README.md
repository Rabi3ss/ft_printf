*This project has been created as part of the 42 curriculum by relyaman*

# ft_printf

## Description

**Goal:** recreate the behavior of the libc `printf` function as a static
library, `libftprintf.a`, that can be linked into future projects.

**Overview:** `ft_printf` takes a format string and a variable number of
arguments, writes the formatted output to standard output.

 Specifier 
-----------
 `%c` 
 `%s` 
 `%p` 
 `%d` 
 `%u` 
 `%x` 
 `%%` 

## Instructions

### Compilation

```bash
make        
make clean  
make fclean 
make re     
```

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (%x)\n", "42", 42, 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```

## Project structure

```
└── ft_printf/
    ├── ft_printf.h
    ├── ft_printf.c
    ├── ft_putnbr.c
    ├── ft_putstr.c
    ├── ft_putchar.c
    ├── ft_puthex.c
    ├── ft_putaddres.c
    ├── ft_putunsi.c
    ├── makefile
    └── Readme.me
```
## Algorithm

**Algorithm:** one pass over the format string. A normal character is
printed directly. After a `%`, the next character is the specifier, and
`print_format` calls the matching function using `va_arg`. Each function
returns how many characters it printed, and `ft_printf` adds them up.

## Resources

### References
- `man 3 printf`, `man 3 stdarg`
- [youtuber video](https://www.youtube.com/watch?v=7Cpqc6I9E9M&t=159s)

### Use of AI
AI (Claude) was used for:
- Explaining how `va_list` / `va_arg` work and common pitfalls
