/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 09:55:32 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/04 14:02:05 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(uintptr_t n)
{
	char	p[17];
	char	*hex;
	int		i;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		p[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	count = i;
	while (i > 0)
	{
		if (write(1, &p[--i], 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_putaddres(void *ptr)
{
	int	ret;
	uintptr_t	n;

	ret = 0;
	n = (uintptr_t)ptr;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (-1 == write(1, "0x", 2))
		return (-1);
	ret = ft_hex(n);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
