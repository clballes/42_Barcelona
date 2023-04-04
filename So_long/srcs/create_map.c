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

static void		ft_map_list(t_map *map, t_map *temp, int fd, char *line);
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
				write_error('1');
		}
		i++;
	}
	return (0);
}

void	ft_openmap(char **argv)
{
	int		fd;
	t_map	*map;
	t_map	*temp;
	char	*line;

	line = NULL;
	map = NULL;
	temp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error('1');
	else
	{
		ft_map_list(map, temp, fd, line);
		if (map == NULL)
			write_error('1');
	}
}

static	void	ft_map_list(t_map *map, t_map *temp, int fd, char *line)
{
	int		rows;
	int		cols;

	rows = 1;
	line = get_next_line(fd);
	temp = ft_lstnew_long(line);
	cols = ft_strlen(line);
	if (line)
	{
		while (line != NULL)
		{
			ft_lstadd_back_long(&map, temp);
			line = get_next_line(fd);
			temp = ft_lstnew_long(line);
			if (line == NULL)
				break ;
			check_len(cols, line);
			rows++;
		}
		map->rows = rows;
		map->cols = cols;
		ft_arraymap(map);
	}
}

void	ft_arraymap(t_map *map)
{
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = map;
	if (map->rows == map->cols)
		write_error('2');
	map->map_array = malloc(sizeof(char *) * map->rows);
	while (i < map->rows && tmp)
	{
		map->map_array[i] = tmp->line;
		i++;
		tmp = tmp->next;
	}
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