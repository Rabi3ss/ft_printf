*This project has been created as part of the 42 curriculum by relyaman*

# ft_printf

## Description

**Goal:** recreate the behavior of the libc `printf` function as a static
library, `libftprintf.a`, that can be linked into future projects.

**Overview:** `ft_printf` takes a format string and a variable number of
arguments, writes the formatted output to standard output, and returns the
number of characters printed (or `-1` on write error). It does not reproduce
the buffer management of the original `printf`.

### Supported conversions

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


## Algorithm and Data Structure

### Data structure
No dynamic data structure is needed, and this is a deliberate choice.
- The only state is the `va_list` (from `<stdarg.h>`), which gives sequential
  access to the arguments. It is passed by value to the conversion handlers,
  or consumed directly with `va_arg`.
- A running `int` counter accumulates the number of bytes written.
- [Bonus: a small `t_format` struct holds the parsed flags, width and
  precision for one conversion, reset on every `%`.]
- **Why:** the format string is read left to right exactly once, so there is
  nothing to store, search or reorder. Allocating memory (lists, buffers)
  would add failure paths and leaks without any benefit.

### Algorithm
1. **Single pass over the format string.** Characters that are not `%` are
   written directly with `write(1, ...)`.
2. **Dispatch on the specifier.** After a `%`, the next character selects a
   handler (via `switch` or a lookup of function pointers). Each handler
   fetches its argument with `va_arg` using the correct type and returns the
   number of bytes written, or `-1` on error.
3. **Number conversion without `malloc`.** Integers are printed by recursion
   (`print_nbr(n / base)` then the last digit), using the base string
   `"0123456789"` or `"0123456789abcdef"` / `"0123456789ABCDEF"`.
   - `%d` / `%i`: the value is promoted to `long` before negation so `INT_MIN`
     does not overflow.
   - `%u` / `%x` / `%X`: the argument is read as `unsigned int`.
   - `%p`: the address is cast to `uintptr_t` (or `unsigned long`) and printed
     in base 16 after `0x`.
4. **Return value.** The counter sums the handlers' return values; if any
   `write` fails, the function returns `-1`.

### Justification
- **Complexity:** O(n) in the length of the format string plus the output,
  with O(log_base(value)) recursion depth per number (at most about 16 frames
  for a 64-bit value in base 16).
- **Memory:** zero heap allocation, so no leaks are possible.
- **Alternatives considered:**
  - *Buffering the output:* fewer `write` syscalls, but it needs a buffer,
    flushing logic and care with partial writes. [Say whether you chose it.]
  - *Building the number as a string with `malloc` (e.g. `ft_itoa`):* simpler
    to pad for bonus flags, but adds allocation and error handling.
  - *A long `if/else` chain for specifiers:* rejected for readability; a
    `switch` or table keeps adding a specifier to a few lines.

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

## Resources

### References
- `man 3 printf`, `man 3 stdarg`
- [youtuber video](https://www.youtube.com/watch?v=7Cpqc6I9E9M&t=159s)

### Use of AI
AI (Claude) was used for:
- Explaining how `va_list` / `va_arg` work and common pitfalls
