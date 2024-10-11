/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabferna <pabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:49:29 by pablo             #+#    #+#             */
/*   Updated: 2024/06/19 11:52:54 by pabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_type(va_list params, char str)
{
	int	c;

	c = 0;
	if (str == 'c')
		c += ft_put_char(va_arg(params, int));
	else if (str == 's')
		c += ft_put_str(va_arg(params, char *));
	else if (str == 'p')
		c += ft_printpointer(va_arg(params, unsigned long));
	else if (str == 'x')
		c += ft_hexa(va_arg(params, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		c += ft_hexa(va_arg(params, unsigned int), "0123456789ABCDEF");
	else if (str == 'd' || str == 'i')
		c += ft_put_nbr(va_arg(params, int));
	else if (str == 'u')
		c += ft_put_unbr(va_arg(params, unsigned int));
	else if (str == '%')
		c += write(1, "%", 1);
	else
		c += write(1, &str, 1);
	return (c);
}
