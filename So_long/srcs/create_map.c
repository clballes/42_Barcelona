/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:02:53 by clballes          #+#    #+#             */
/*   Updated: 2023/04/04 15:06:30 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"
#include "libft.h"

static void		ft_map_list(t_map *map, t_line *temp, int fd);
static void		create_copy(t_map *map);

int	ft_open_ber(char **argv)
{
	int	i;

	i = 0;
	while (*argv[1] && argv[1][i])
	{
		if (argv[1][i] == '.')
		{
			i++;
			if (argv[1][i] == 'b' && argv[1][i + 1] == 'e'
					&& argv[1][i + 2] == 'r')
				return (1);
			else
				write_error('0');
		}
		i++;
	}
	return (0);
}

void	ft_openmap(char **argv)
{
	int		fd;
	t_map	*map;
	t_line	*temp;

	temp = malloc(sizeof(t_line));
	map = malloc(sizeof(t_map));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error('1');
	else
	{
		ft_map_list(map, temp, fd);
		if (map == NULL)
			write_error('1');
	}
}

static	void	ft_map_list(t_map *map, t_line *temp, int fd)
{
	int		rows;
	int		cols;
	t_line	*list;

	rows = 1;
	temp->line = get_next_line(fd);
	if (temp->line == NULL)
		write_error('5');
	cols = ft_strlen(temp->line);
	if (temp->line)
	{
		while (1)
		{
			list = ft_lstnew_long(get_next_line(fd));
			if (list->line == NULL)
				break ;
			ft_lstadd_back_long(&temp, list);
			check_len(cols, list);
			rows++;
		}
		map->rows = rows;
		map->cols = cols;
		ft_arraymap(map, temp);
	}
}

void	ft_arraymap(t_map *map, t_line *temp)
{
	int		i;

	i = 0;
	if (map->rows == map->cols)
		write_error('2');
	map->map_array = malloc(sizeof(char *) * map->rows);
	while (i < map->rows)
	{
		map->map_array[i] = temp->line;
		i++;
		temp = temp->next;
	}
	free(temp);
	check_map_walls(map, (map->rows - 1), (map->cols - 1));
	create_copy(map);
}

static void	create_copy(t_map *map)
{
	char	**cy_map_arr;
	int		i;
	int		j;

	i = 0;
	cy_map_arr = malloc(sizeof(char *) * map->rows);
	if (cy_map_arr == NULL)
		return ;
	while (i < map->rows)
	{
		cy_map_arr[i] = malloc(sizeof(char) * map->cols);
		if (cy_map_arr[i] == NULL)
			return ;
		j = 0;
		while (j < map->cols)
		{
			cy_map_arr[i][j] = map->map_array[i][j];
			j++;
		}
		i++;
	}
	has_valid_path(map, cy_map_arr);
}
