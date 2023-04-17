/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:02:53 by clballes          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:44 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"
#include "libft.h"

static void		ft_map_list(t_map *map, int fd);
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

	map = malloc(sizeof(t_map));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error('1');
	else
	{
		ft_map_list(map, fd);
		if (map == NULL)
			write_error('1');
	}
}

static	void	ft_map_list(t_map *map, int fd)
{
	int		rows;
	int		cols;
	char	*line;

	rows = 0;
	cols = 0;
	map->map_unid = NULL;
	line = get_next_line(fd);
	cols = ft_strlen(line);
	if (!line)
		write_error('5');
	while (line)
	{
		if (!map->map_unid)
			map->map_unid = ft_strdup(line);
		else
			map->map_unid = ft_strjoin(map->map_unid, line);
		map->map_unid = ft_strjoin(map->map_unid, "\n");
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	map->rows = rows;
	map->cols = cols;
	ft_arraymap(map);
}

void	ft_arraymap(t_map *map)
{
	if (map->rows == map->cols)
		write_error('2');
	map->map_array = ft_split(map->map_unid, '\n');
	check_map_walls(map, (map->rows - 1), (map->cols - 1));
	create_copy(map);
}

static void	create_copy(t_map *map)
{
	char	**cy_map_arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cy_map_arr = malloc(sizeof(char *) * map->rows);
	if (cy_map_arr == NULL)
		return ;
	while (i < map->rows)
	{
		cy_map_arr[i] = ft_strdup(map->map_array[i]);
		i++;
	}
	has_valid_path(map, cy_map_arr);
}
