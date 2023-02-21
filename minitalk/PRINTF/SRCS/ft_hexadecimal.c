/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:17:22 by clballes          #+#    #+#             */
/*   Updated: 2022/07/14 15:31:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_create_str(unsigned long long int j)
{
	char	*str;
	int		i;

	i = ft_hexadecimal_len(j);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	return (str);
}

char	*ft_hexadecimal(unsigned long long int j)
{
	unsigned long long int	hexadecimal;
	int						i;
	char					*str;
	char					letter;

	str = ft_create_str(j);
	i = ft_hexadecimal_len(j);
	hexadecimal = j % 16;
	while (i > 0)
	{
		if (hexadecimal >= 10 && hexadecimal <= 15)
		{	
			letter = ft_numbers_to_letters(hexadecimal);
			str[i - 1] = letter;
			i--;
		}
		else
		{
			str[i - 1] = hexadecimal + '0';
			i--;
		}
	j = j / 16;
	hexadecimal = j % 16;
	}
	return (str);
}

char	ft_numbers_to_letters(unsigned long long int hexadecimal)
{
	char			letter;
	unsigned int	cont;

	cont = 9;
	letter = '@';
	while (cont < hexadecimal)
	{
		letter++;
		cont++;
	}
	return (letter);
}

int	ft_hexadecimal_len(unsigned long long int j)
{
	int	result;

	result = 0;
	if (j == 0)
		return (1);
	while (j > 0)
	{
		result++;
		j = j / 16;
	}
	return (result);
}
