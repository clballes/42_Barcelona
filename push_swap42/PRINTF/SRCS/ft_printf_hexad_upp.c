/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexad_upp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:41:44 by clballes          #+#    #+#             */
/*   Updated: 2022/07/12 19:21:53 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexad_upp(unsigned int i)
{
	int		cont;
	char	*str;

	str = ft_hexadecimal(i);
	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] >= 97 && str[cont] <= 102)
			str[cont] -= 32;
		ft_putchar(str[cont]);
	cont ++;
	}
	free(str);
	return (cont);
}
