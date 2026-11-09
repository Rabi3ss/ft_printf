/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:02:30 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/09 21:41:38 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_putchar (va_arg(ap, int));
	else if (spec == 's')
		count = ft_putstr (va_arg(ap, void *));
	else if (spec == 'p')
		count = ft_putaddres (va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count = ft_putnbr (va_arg(ap, int));
	else if (spec == 'u')
		count = ft_putunsi (va_arg(ap, unsigned int));
	else if (spec == 'x' || spec == 'X')
		count = ft_puthex (va_arg(ap, unsigned int), spec);
	else if (spec == '%')
	{
		count = ft_putchar ('%');
	}
	else
		ft_putchar(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += print_format(format[++i], ap);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
