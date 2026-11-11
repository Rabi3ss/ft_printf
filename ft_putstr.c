/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:21:22 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/10 18:44:07 by relyaman         ###   ########.fr       */
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
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
