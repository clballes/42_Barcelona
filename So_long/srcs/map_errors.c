/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:02:53 by clballes          #+#    #+#             */
/*   Updated: 2023/03/07 12:14:25 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"
#include "libft.h"

static void		ft_openmap(char **argv);
static t_map	*ft_map_list(t_map *map, t_map *temp, int fd);

void	ft_open_ber(char **argv)
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
				ft_openmap(argv);
			else
				write_error();
		}
		i++;
	}
}

static void	ft_openmap(char **argv)
{
	int		fd;
	t_map	*map;
	t_map	*temp;

	map = NULL;
	temp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_error();
	else
	{
		map = ft_map_list(map, temp, fd);
		if (map == 0)
			write_error();
	}
}

static t_map	*ft_map_list(t_map *map, t_map *temp, int fd)
{
	char	*line;
	int		rows;
	int		cols;
	int		cols2;

	rows = 0;
	line = get_next_line(fd);
	temp = ft_lstnew_long(line);
	cols = ft_strlen(line) - 1;
	// printf("la cols es %d\n", cols);

	if (line)
	{
		while (line != NULL)
		{
			ft_lstadd_back_long(&map, temp);
			line = get_next_line(fd);
			cols2 = ft_strlen(line) - 1;
			// printf("la cols2 es %d\n", cols2);
				printf("la cols foraa if es %d\n", cols);
				printf("la cols2 foraa if es %d\n", cols2);
			temp = ft_lstnew_long(line);
			if ((cols != cols2) && cols != (cols2 + 1))
			{
				printf("la cols if es %d\n", cols);
				printf("la cols2 if es %d\n", cols2);
				printf("la line es %s\n", line);
				write_error();
			}
			else
				break ;
			rows++;
		}
		map->rows = rows;
		map->cols = cols; //numero de cols es contant el null
		// printf("la row es %d\n", rows);
		// printf("la cols es %d\n", cols);
		ft_arraymap(map);
	}
	else
		return (0);
	return (map);
}

void	ft_arraymap(t_map *map)
{
	char	**map_arr;
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = map;
	if (map->rows == map->cols)
		write_error();
	map_arr = malloc(sizeof(char *) * map->rows);
	while (i < map->rows && tmp)
	{
		map_arr[i] = tmp->line;
		i++;
		tmp = tmp->next;
	}
	check_map_walls(map_arr, (map->rows - 1), (map->cols - 1));
}

// void    print_list (t_map *map)
// {
//     t_map	*temp_a;
//     temp_a = map;
//     while (temp_a)
//     {
//         printf("valor en lista:%s\n", temp_a->line);
//         temp_a = temp_a->next;
//     }
//     printf("----------------------------------------\n");
// }