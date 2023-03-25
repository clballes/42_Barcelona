/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:36:39 by clballes          #+#    #+#             */
/*   Updated: 2023/03/22 12:48:35 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

static int	is_valid(int row, int col, t_map *map);
static int	is_move_valid(char **cy_map_arr, int row, int col);
static int	backtrack(char **cy_map_arr, int row, int col, t_map *map);
static void	check_startpos(char **cy_map_arr, t_map *map, int i, int j);

static int	is_valid(int row, int col, t_map *map)
{
    return (row >= 0 && row < map->rows && col >= 0 && col < map->cols);
}

// function to check if a given node is a valid move (i.e., not a wall)
static int	is_move_valid(char **cy_map_arr, int row, int col)
{
	return (cy_map_arr[row][col] != '1');
}

// function to perform backtracking on the map_arr
static int	backtrack(char **cy_map_arr, int row, int col, t_map *map)
{
	int	next_row;
	int	next_col;
	int	i;
	int	delta_row[] = {-1, 0, 1, 0};
	int	delta_col[] = {0, 1, 0, -1};

	next_row = 0;
	next_col = 0;
	i = 0;
	if (cy_map_arr[row][col] == 'E' && map->coll == 0)
		return (1);
	if (cy_map_arr[row][col] == 'C')
		map->coll--;
	cy_map_arr[row][col] = 'V';
	while (i < 4)
	{
		next_row = row + delta_row[i];
		next_col = col + delta_col[i];
		if (is_valid(next_row, next_col, map)
			&& is_move_valid(cy_map_arr, next_row, next_col)
			&& cy_map_arr[next_row][next_col] != 'V')
		{
			if (backtrack(cy_map_arr, next_row, next_col, map))
				return (1);
		}
		i++;
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
}

void	has_valid_path(t_map *map, char **cy_map_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_startpos(cy_map_arr, map, i, j);
	if (backtrack(cy_map_arr, map->start, map->end, map) && map->coll == 0)
    {
	    printf("Valid path exists!\n");
		window();
	}
	else
        printf("No valid path exists!\n");
}
