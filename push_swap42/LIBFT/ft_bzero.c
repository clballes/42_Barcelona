/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:48:17 by clballes          #+#    #+#             */
/*   Updated: 2022/06/14 11:15:30 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//	 ft_memset(s, 0, n); 

void	ft_bzero(void *s, size_t n)
{	
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}
