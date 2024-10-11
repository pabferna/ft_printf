/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabferna <pabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:49:33 by pablo             #+#    #+#             */
/*   Updated: 2024/06/19 11:55:20 by pabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		c += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		c += ft_put_nbr(n / 10);
		c += write(1, &(char){n % 10 + '0'}, 1);
	}
	else
		c += write(1, &(char){n % 10 + '0'}, 1);
	return (c);
}

int	ft_put_unbr(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
	{
		c += ft_put_nbr(n / 10);
		c += write(1, &(char){n % 10 + '0'}, 1);
	}
	else
		c += write(1, &(char){n % 10 + '0'}, 1);
	return (c);
}

int	ft_hexa(unsigned long n, char *base)
{
	int	c;

	c = 0;
	if (n >= 16)
	{
		c += ft_hexa(n / 16, base);
		c += ft_put_char(base[n % 16]);
	}
	else
		c += ft_put_char(base[n % 16]);
	return (c);
}

int	ft_printpointer(unsigned long n)
{
	int	c;

	c = 0;
	if (n == 0)
		c += write(1, "(nil)", 5);
	else
	{
		c += write(1, "0x", 2);
		c += ft_hexa(n, "0123456789abcdef");
	}
	return (c);
}
