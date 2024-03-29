/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:29:31 by clballes          #+#    #+#             */
/*   Updated: 2023/04/17 19:23:14 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"
#include "libft.h"
#include "../mlx/mlx.h"

static void	check_coll(t_map *map, int rows, int cols);
static void	check_letter(t_map *map, char letter, int rows, int cols);

void	check_map_walls(t_map *map, int rows, int cols)
{
	int	i;

	i = 0;
	if (map->map_array[0][i] == '1' && map->map_array[rows][i] == '1')
	{
		while (i <= cols)
		{
			if (map->map_array[0][i] != '1' || map->map_array[rows][i] != '1')
				write_error('4');
			i++;
		}
	}
	i = 0;
	if (map->map_array[i][0] == '1' && map->map_array[i][cols] == '1')
	{
		while (i <= rows)
		{
			if (map->map_array[i][0] != '1' || map->map_array[i][cols] != '1')
				write_error('4');
			i++;
		}
	}
	else
		write_error('4');
	check_coll(map, rows, cols);
}

static void	check_coll(t_map *map, int rows, int cols)
{
	int		i;
	char	*letter;
	int		j;

	i = 0;
	j = 0;
	letter = "10CEP";
	while (**map->map_array && i <= rows)
	{
		j = 0;
		while (j <= cols)
		{
			if (ft_strncmp_long(map->map_array[i][j], letter) == 0)
				j++;
			else
				write_error ('3');
		}
		i++;
	}
	check_letter(map, 'C', rows, cols);
}

static void	check_letter(t_map *map, char letter, int rows, int cols)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (**map->map_array && i <= rows)
	{
		j = 0;
		while (j <= cols)
		{
			if (map->map_array[i][j] == letter)
				c++;
			j++;
		}
		i++;
	}
	if ((letter == 'P' || letter == 'E') && c != 1)
		write_error('3');
	else if (letter == 'C' && c == 0)
		write_error('3');
	if (letter == 'C')
		check_letter(map, 'E', rows, cols);
	else if (letter == 'P')
		check_letter(map, 'P', rows, cols);
}

void	check_len(int cols, char *line)
{
	int	colsnext;

	colsnext = ft_strlen(line);
	if (cols != colsnext)
		write_error('2');
}

void	check_move_collec(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E' && map->collective == 0)
	{
		put_string(map);
		close_click(map);
	}
	if (map->map_array[map->start][map->end] == 'C')
	{
		map->collective--;
		map->map_array[map->start][map->end] = 'X';
	}
	if (map->map_array[map->start][map->end] == 'P'
		|| map->map_array[map->start][map->end] == 'X')
	{
		if (map->i == 0)
			ft_loop(map, map->x, map->y);
		else
		{
			map->put_x[map->i] = map->x;
			map->put_y[map->i] = map->y;
			map->i++;
		}
		map->map_array[map->start][map->end] = '0';
	}
}
