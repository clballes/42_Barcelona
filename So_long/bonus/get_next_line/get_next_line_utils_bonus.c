/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:35 by clballes          #+#    #+#             */
/*   Updated: 2022/10/04 17:43:29 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/get_next_line.h"
#include "libft.h"

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_protect(s1);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{		
		ptr[i + j] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[(i) + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_protect(char *s1)
{
	s1 = (char *)malloc(sizeof(char));
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strchr_get(char *s, int c)
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
