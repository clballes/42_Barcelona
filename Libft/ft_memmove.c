/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:59:55 by clballes          #+#    #+#             */
/*   Updated: 2022/05/16 17:55:50 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrsrc = (unsigned char *) src;
	ptrdst = (unsigned char *) dst;
	if (ptrdst == ptrsrc || len == 0)
		return (dst);
	if (ptrdst > ptrsrc)
	{
		while (len > 0)
		{	
			ptrdst[len - 1] = ptrsrc[len - 1];
			len--;
		}	
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
