/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:43:33 by clballes          #+#    #+#             */
/*   Updated: 2022/07/28 13:16:20 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *str)
{
	int	cont;

	cont = 0;
	if (str == NULL)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	while (str[cont] != '\0')
	{		
		write(1, &str[cont], 1);
		cont++;
	}
	return (cont);
}
