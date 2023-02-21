/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:45:37 by clballes          #+#    #+#             */
/*   Updated: 2022/07/12 19:20:50 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_int(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n == 2147483647)
		return (write (1, "2147483647", 10));
	else if (n < 0)
	{
		result += ft_putchar('-');
		n *= -1;
		result += ft_printf_int(n);
	}
	else if (n >= 10)
	{
		result += ft_printf_int(n / 10);
		result += ft_printf_int(n % 10);
	}
	else
		result += ft_putchar(n + '0');
	return (result);
}
