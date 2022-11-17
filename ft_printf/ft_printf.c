/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:35:16 by clballes          #+#    #+#             */
/*   Updated: 2022/07/01 18:22:35 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_searchtype(va_list args, char c);
int			ft_printf(const char *str, ...)
{
	int	i;
	int	resultado;
	va_list args;
	va_start(args, str);

	i = 0;
	resultado = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			resultado += ft_searchtype(args, str[i + 1]);		
		else
			resultado += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int		ft_searchtype(va_list args, char c)
{
	int	resultado;
	resultado = 0;
	if (c == 'c')
		resultado = ft_printf_character(va_arg(args, int));
	/*if (c == 's')
		resultado = ft_printf_string(va_arg(args, char *));
	if (c == 'p')
		ft_printf_pointer(va_arg(args, void *));
	if (c == 'd')
		ft_printf_decimal();
	if (c == 'i')
		ft_printf_int();
	if (c == 'u')
		ft_printf_unsigned_decimal();
	if (c == 'x')
		ft_printf_hexad_low();
	if (c == 'X')
		ft_printf_hexad_upp();
	if (c == '%')
		ft_printf_percent();
	else 
		ft_putchar();
*/
	return (resultado);
}
