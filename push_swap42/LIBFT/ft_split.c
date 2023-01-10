/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:02:43 by clballes          #+#    #+#             */
/*   Updated: 2022/07/14 13:29:35 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(const char *s, char c)
{
	int	i;	
	int	n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
	i++;
	}
	return (n);
}

char	**ft_free_split(char	**split, int n)
{
	while (n > 0)
	{
		n--;
		free(split[n]);
	}
	free(split);
	return (0);
}

char	**ft_searchword(const char *s, char c, char **split)
{
	int		n;
	int		i;
	int		start;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			start = i;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[n] = ft_substr(s, start, (i - start) + 1);
			if (!split[n])
				return (ft_free_split(split, n));
			n++;
		}
		i++;
	}
	split[n] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	split = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_searchword(s, c, split);
	return (split);
}
