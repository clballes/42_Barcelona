/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:35 by clballes          #+#    #+#             */
/*   Updated: 2022/09/05 15:31:29 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;

	ptr = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);

	if (!s1 || !s2)
		return (NULL);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{		
		ptr[i + j] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
//	printf("storage es %s\n buffer es %s\n", s1, s2);
//	printf("strjoin storage = %s\n", ptr);
	return (ptr);
}

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

size_t	ft_strlen(const char *str)
{	
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
