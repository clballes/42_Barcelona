/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:35:55 by clballes          #+#    #+#             */
/*   Updated: 2022/07/14 14:56:02 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long long p);

int	ft_printf_pointer(void *p)
{
	int	result;

	if (!p)
		return (write(1, "0x0", 3));
	ft_putchar('0');
	ft_putchar('x');
	result = ft_put_hex((unsigned long long)p);
	result = result + 2;
	return (result);
}

int	ft_put_hex(unsigned long long p)
{
	int		result;
	char	*hex;

	result = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
	{
		result += ft_put_hex(p / 16);
		result += ft_put_hex(p % 16);
	}
	else
		result += ft_putchar(hex[p]);
	return (result);
}
