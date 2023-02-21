/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexad_low.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:38:41 by clballes          #+#    #+#             */
/*   Updated: 2022/07/14 15:29:24 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexad_low(unsigned int j)
{
	int		cont;
	char	*str;

	str = ft_hexadecimal(j);
	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] >= 65 && str[cont] <= 70)
			str[cont] += 32;
		ft_putchar(str[cont]);
	cont ++;
	}
	free(str);
	return (cont);
}
