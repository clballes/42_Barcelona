/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:17:22 by clballes          #+#    #+#             */
/*   Updated: 2022/07/01 18:23:39 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_hexadecimal(int j);
char	ft_numbers_to_letters(int hexadecimal);
char	*ft_hexadecimal(int j)
{
	int	temp;
	int	hexadecimal;
	char	*str;
	int	i;

	str = malloc(sizeof(char *));
	temp = 0;
	temp = j / 16;
	hexadecimal = j % 16;
	i = hexadecimal;
	str[i] = hexadecimal + '0';
	while (temp > 0)
	{
		if (hexadecimal >= 10 && hexadecimal <= 15)
			str[i] = ft_numbers_to_letters(hexadecimal);
		hexadecimal = temp % 16;
		temp = temp/ 16;
		i--;
		str[i] = hexadecimal + '0';
	}	
	return (&str[i]);
}

char	ft_numbers_to_letters(int hexadecimal){
	char	letter;
	int	cont;
	
	cont = 9;
	letter = '@';
	while (cont < hexadecimal)
	{
		letter++;
		cont++;
	}
	return(letter);
}
