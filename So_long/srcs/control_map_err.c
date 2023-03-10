/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:29:31 by clballes          #+#    #+#             */
/*   Updated: 2023/03/10 12:31:54 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"
#include "libft.h"
// static void	check_coll(char **map_arr, int rows, int cols);

void	check_map_walls(char **map_arr, int rows, int cols)
{
	int	i;

	i = 0;
	if (map_arr[0][i] == '1' && map_arr[rows][i] == '1')
	{
		while (i <= cols)
		{
			if (map_arr[0][i] != '1' || map_arr[rows][i] != '1')
				write_error();
			i++;
		}
	}
	i = 0;
	if (map_arr[i][0] == '1' && map_arr[i][cols] == '1')
	{
		while (i <= rows)
		{
			if (map_arr[i][0] != '1' || map_arr[i][cols] != '1')
				write_error();
			i++;
		}
	}
	else
		write_error();
	// check_coll(map_arr, rows, cols);
}
