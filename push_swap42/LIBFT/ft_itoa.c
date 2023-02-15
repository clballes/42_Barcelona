/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:24:20 by clballes          #+#    #+#             */
/*   Updated: 2022/06/20 12:13:22 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_number(int n)
{
	int			i;
	long int	j;

	j = (long int)n;
	i = 0;
	if (j <= 0)
	{
		i++;
		j *= -1;
	}	
	while (j > 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	j;

	j = (long int)n;
	len = ft_len_number(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		j *= -1;
	}	
	while (--len >= 0)
	{
		if (n < 0 && len == 0)
			break ;
		str[len] = '0' + j % 10;
		j = j / 10;
	}
	str[ft_len_number(n)] = '\0';
	return (str);
}
