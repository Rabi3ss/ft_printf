/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:21:22 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/04 20:48:22 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		count;

	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[count])
	{
		if (-1 == write(1, &s[count], 1))
			return (-1);
		count++;
	}
	return (count);
}
