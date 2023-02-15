/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:24:46 by clballes          #+#    #+#             */
/*   Updated: 2022/06/10 16:10:46 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// #include <stdio.h>
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (j < len && haystack[j] != '\0')
	{
		i = 0;
		while (haystack[j + i] == needle[i] && haystack[j + i] != '\0'
			&& j + i < len)
		{
			i++;
		}
		if (i == ft_strlen(needle))
			return ((char *)&haystack[j]);
		j++;
	}	
	return (0);
}
