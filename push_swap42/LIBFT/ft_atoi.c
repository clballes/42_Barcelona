/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:37:09 by clballes          #+#    #+#             */
/*   Updated: 2022/06/14 10:47:58 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
				sign *= -1;
	str++;
	}
	if (str[1] == '-' || str[1] == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
			res = res * 10 + *str - '0';
			str++;
	}
	return (res * sign);
}
