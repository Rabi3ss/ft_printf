/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:45:30 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/09 22:00:49 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	char	p[9];
	char	*hex;
	int		i;
	int		count;

	hex = NULL;
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
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
	count = i;
	while (i > 0)
		write(1, &p[--i], 1);
	return (count);
}
