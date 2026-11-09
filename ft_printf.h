/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relyaman <relyaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:51:20 by relyaman          #+#    #+#             */
/*   Updated: 2026/11/09 18:48:30 by relyaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putaddres(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char c);
int	ft_putunsi(unsigned int n);

#endif
