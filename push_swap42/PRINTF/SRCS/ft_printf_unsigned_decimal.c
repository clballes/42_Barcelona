/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:48:03 by clballes          #+#    #+#             */
/*   Updated: 2022/07/12 19:31:01 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_decimal(unsigned int n)
{
	int	result;

	result = 0;
	if (n >= 10)
	{
		result += ft_printf_unsigned_decimal(n / 10);
		result += ft_printf_unsigned_decimal(n % 10);
	}
	else
		result += ft_putchar(n + '0');
	return (result);
}
