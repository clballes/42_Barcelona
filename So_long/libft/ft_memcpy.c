/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:34:37 by clballes          #+#    #+#             */
/*   Updated: 2022/05/16 17:54:29 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrsrc = (unsigned char *) src;
	ptrdst = (unsigned char *) dst;
	i = 0;
	if (!ptrsrc && !ptrdst)
		return (0);
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}	
	return (dst);
}
