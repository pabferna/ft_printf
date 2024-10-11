/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabferna <pabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:49:16 by pablo             #+#    #+#             */
/*   Updated: 2024/06/23 13:20:53 by pabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_type(va_list params, char str);

int	ft_put_char(int c);
int	ft_hexa(unsigned long n, char *base);
int	ft_put_nbr(int n);
int	ft_put_unbr(unsigned int n);
int	ft_printpointer(unsigned long n);

#endif