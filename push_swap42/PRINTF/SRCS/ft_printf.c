/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:35:16 by clballes          #+#    #+#             */
/*   Updated: 2022/07/13 19:52:48 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_searchtype(va_list args, char c);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		resultado;
	va_list	args;

	va_start(args, str);
	i = 0;
	resultado = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			resultado += ft_searchtype(args, str[i + 1]);
			i++;
		}
		else
			resultado += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (resultado);
}

int	ft_searchtype(va_list args, char c)
{
	int	resultado;

	resultado = 0;
	if (c == 'c')
		resultado = ft_printf_character(va_arg(args, int));
	if (c == 's')
		resultado = ft_printf_string(va_arg(args, char *));
	if (c == 'p')
		resultado = ft_printf_pointer(va_arg(args, void *));
	if (c == 'd')
		resultado = ft_printf_decimal(va_arg(args, signed int));
	if (c == 'i')
		resultado = ft_printf_int(va_arg(args, int));
	if (c == 'u')
		resultado = ft_printf_unsigned_decimal(va_arg(args, unsigned int));
	if (c == 'x')
		resultado = ft_printf_hexad_low(va_arg(args, unsigned int));
	if (c == 'X')
		resultado = ft_printf_hexad_upp(va_arg(args, unsigned int));
	if (c == '%')
		resultado = ft_printf_percent();
	return (resultado);
}
