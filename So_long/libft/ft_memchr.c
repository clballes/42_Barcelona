/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:21:01 by clballes          #+#    #+#             */
/*   Updated: 2022/05/24 13:01:19 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;

	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c)
			return ((void *)&s[i]);
	i++;
	}
	return (NULL);
}
