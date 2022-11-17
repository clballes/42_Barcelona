/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:23:52 by clballes          #+#    #+#             */
/*   Updated: 2022/06/14 12:39:04 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen (dst);
	j = ft_strlen(src);
	k = 0;
	if (dstsize == 0)
		return (j);
	if (dstsize <= i)
		return (dstsize + j);
	dstsize -= i;
	while (--dstsize && src[k])
	{
		dst[i + k] = src[k];
			++k;
	}
	dst[i + k] = '\0';
	return (i + j);
}
