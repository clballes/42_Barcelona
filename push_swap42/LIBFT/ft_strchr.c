/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:18:50 by clballes          #+#    #+#             */
/*   Updated: 2022/06/17 17:20:14 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == c)
			return ((char *)s);
	s++;
	}
	return (0);
}
