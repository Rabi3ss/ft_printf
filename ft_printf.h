
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stddef.h>
#include <unistdio.h>

int     ft_printf(const char *restrict format, ...);
void    ft_putchar(char c);
void    ft_putstr(char *s);
void    ft_putnbr(int n);
void    ft_puthex(int n, char c);


#endif
