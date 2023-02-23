/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:22:11 by clballes          #+#    #+#             */
/*   Updated: 2022/06/17 17:44:42 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;

	if (s1 == 0 || set == 0)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
			i++;
	while (s1[i] && ft_strrchr(set, s1[j - 1]))
			j--;
	trim = ft_substr(s1, i, j - i);
	return (trim);
}
