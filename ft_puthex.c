/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:45:30 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/04 20:46:04 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	char	p[17];
	char	*hex;
	int		i;

	hex = NULL;
	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (n > 0)
	{
		p[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	p[i] = '\0';
	while (i > 0)
		write(1, &p[--i], 1);
	return (0);
}
