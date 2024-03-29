/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:11:58 by clballes          #+#    #+#             */
/*   Updated: 2023/04/12 11:43:30 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"
#include "libft.h"

void	write_error(char error)
{
	write (2, "Error: ", 7);
	if (error == '0')
		write (2, "Not ber extension\n", 18);
	else if (error == '1')
		write (2, "Map not loaded\n", 15);
	else if (error == '2')
		write (2, "Map not rectangular\n", 20);
	else if (error == '3')
		write (2, "Map not minimum elements or letters accepted\n", 45);
	else if (error == '4')
		write (2, "Map not sourrounded by walls\n", 29);
	else if (error == '5')
		write (2, "Empty map\n", 10);
	else if (error == '6')
		write (2, "Different lenght\n", 17);
	else if (error == '7')
		write (2, "Not enough arguments\n", 21);
	else if (error == '8')
		write (2, "Impossible Exit\n", 16);
	exit (1);
}

int	ft_strncmp_long(char c, char *s2)
{
	int	i;

	i = 0;
	while (c != '\0' && s2[i] != '\0')
	{
		while (c != s2[i] && s2[i] != '\0')
			i++;
		if (c == s2[i])
			return (0);
		else
			return (1);
	}
	return (1);
}
