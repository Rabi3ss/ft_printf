
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int     ft_printf(const char *restrict format, ...);
int    ft_putchar(char c);
int    ft_putstr(char *s);
int    ft_putnbr(int n);
int    ft_puthex(unsigned int n, char c);
int	ft_putunsi(unsigned int n);


#endif
