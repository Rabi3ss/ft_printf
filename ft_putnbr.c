/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:38:09 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/10 18:43:37 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	ln;
	char	num;
	int		count;

	count = 1;
	ln = n;
	if (n < 0)
	{
		write(1, "-", 1);
		ln *= (-1);
		count = 2;
	}
	if ((ln / 10) != 0)
		count += ft_putnbr (ln / 10);
	num = (ln % 10) + '0';
	write (1, &num, 1);
	return (count);
}
