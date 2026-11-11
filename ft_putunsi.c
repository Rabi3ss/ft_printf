/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 09:47:19 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/10 18:44:20 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsi(unsigned int n)
{
	long	ln;
	char	num;
	int		count;

	count = 1;
	ln = n;
	if ((ln / 10) != 0)
		count += ft_putunsi (ln / 10);
	num = (ln % 10) + '0';
	write (1, &num, 1);
	return (count);
}
