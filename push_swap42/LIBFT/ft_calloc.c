/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:57:17 by clballes          #+#    #+#             */
/*   Updated: 2022/06/14 12:44:11 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc (count * size);
	if (count == '0' || size == '0')
		return (NULL);
	if (ptr == NULL)
		return (0);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}	
	return (ptr);
}
