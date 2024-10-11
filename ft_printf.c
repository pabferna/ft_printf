/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabferna <pabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:12:33 by pabferna          #+#    #+#             */
/*   Updated: 2024/06/23 13:15:35 by pabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	params;
	int		c;

	va_start(params, str);
	c = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			c += ft_type(params, *str);
		}
		else
			c += ft_put_char(*str);
		str++;
	}
	va_end(params);
	return (c);
}
