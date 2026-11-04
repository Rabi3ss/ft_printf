/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:02:30 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/04 23:48:22 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if(spec == 'c')
		count = ft_putchar();
	else if (spec == 's')
		count = ft_putstr();
	else if (spec == 'p')
		count = ft_putaddres();
	else if (spec == 'd' || spec == 'i')
		count = ft_putnbr();
	else if (spec == 'u')
		count = ft_putunsi();
	else if (spec == 'x' || spec == 'X')
		count = ft_puthex();
	else if (spec == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
	}
	else
		if(write(1, (char)ap,1) == -1)
			return (-1);
}

int	ft_printf(const char *, ...)
{
	va_list	ap;
	int	count;
	int	i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if(format[i] == '%')
			count += print_format(format[++i], ap);
		else
			count += ft_putchar(&format[i]);
		i++;
	}
	va_end(ap);
	return count;
}
