/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:02:30 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/11 18:18:04 by relyaman         ###   ########.fr       */
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
		count = ft_putchar ('%');
	else
	{
		count = ft_putchar ('%');
		count = ft_putchar (spec);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format) == 0)
			{
				va_end(ap);
				return (-1);
			}
			count += print_format(*format, ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
