/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:36:39 by clballes          #+#    #+#             */
/*   Updated: 2023/04/17 19:25:52 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_move_valid(char **cy_map_arr, int row, int col);
static int	backtrack(char **cy_map_arr, int row, int col, t_map *map);
static void	check_startpos(char **cy_map_arr, t_map *map, int i, int j);

static int	is_move_valid(char **cy_map_arr, int row, int col)
{
	return (cy_map_arr[row][col] != '1' && (row >= 0) && (col >= 0));
}

static int	backtrack(char **cy_map_arr, int row, int col, t_map *map)
{
	int			i;
	static char	c = 'V';

	i = -1;
	if (cy_map_arr[row][col] == 'E' && map->coll == 0)
		return (1);
	if (cy_map_arr[row][col] == 'C')
		map->coll--;
	if (cy_map_arr[row][col] != 'E')
		cy_map_arr[row][col] = c;
	while (++i < 4)
	{
		map->next_row = row + map->delta_row[i];
		map->next_col = col + map->delta_col[i];
		if (is_move_valid(cy_map_arr, map->next_row, map->next_col)
			&& cy_map_arr[map->next_row][map->next_col] != c)
			if (backtrack(cy_map_arr, map->next_row, map->next_col, map))
				return (1);
	}
	if (map->coll == 0)
	{
		c = 'X';
		return (backtrack(cy_map_arr, map->next_row, map->next_col, map));
	}
	return (0);
}

static void	check_startpos(char **cy_map_arr, t_map *map, int i, int j)
{
	int	coll;
	int	start;
	int	end;

	coll = 0;
	start = 0;
	end = 0;
	while (**cy_map_arr && i <= (map->rows - 1))
	{
		j = 0;
		while (j <= map->cols)
		{
			if (cy_map_arr[i][j] == 'P')
			{
				map->start = i;
				map->end = j;
			}
			if (cy_map_arr[i][j] == 'C')
				coll++;
			j++;
		}
		i++;
	}
	map->coll = coll;
	map->collective = coll;
}

static void	check_0(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->sea = 0;
	while (map->map_array && i < map->rows)
	{
		j = 0;
		while (j <= map->cols)
		{
			if (map->map_array[i][j] == '0')
				map->sea++;
			j++;
		}
		i++;
	}
	map->sea = map->sea + map->collective;
}

void	has_valid_path(t_map *map, char **cy_map_arr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	init_delta(map);
	check_startpos(cy_map_arr, map, i, j);
	if (backtrack(cy_map_arr, map->start, map->end, map) && map->coll == 0)
	{
		write(1, "Valid path exists! \n", 20);
		check_0(map);
		open_window(map);
	}
	else
		write(1, "No valid path exists! \n", 22);
}
