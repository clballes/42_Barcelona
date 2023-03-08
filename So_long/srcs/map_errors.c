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

void	ft_checkber(char **argv)
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
				printf("Not ber extension, try an other map!\n");
		}
		i++;
	}
}

void	ft_openmap(char **argv)
{
	int		fd;
	t_map	*map = NULL;
	t_map	*temp = NULL;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("ERRROR OPENINNG\n");
	else
	{
		map = ft_createmap(map, temp, fd);
		if (map == 0)
			printf("the map is empty!\n");
	}
	// print_list(map);
}

t_map	*ft_createmap(t_map *map, t_map *temp, int fd)
{
	char	*line;
	int		rows;
	int		cols;

	rows = 0;
	line = get_next_line(fd);
	temp = ft_lstnew_long(line);
	cols = ft_strlen(line); //si fos - 1 es le numero real, perq te en compte el null
	rows++;
	printf("la line number es: %d\n", cols);
	if (line)
	{
		while (line != NULL)
		{
			ft_lstadd_back_long(&map, temp);
			line = get_next_line(fd);
			temp = ft_lstnew_long(line);
			rows++;
		}
		printf("las rows son: %d\n", rows);
		ft_arraymap(map, cols, rows);
	}
	else
		return (0);
	return (map);
}

void	ft_arraymap(t_map *map, int cols, int rows)
{
	char map_arr[rows][cols];
	int i;
	t_map *tmp;
	int len_cols;
	// int	len_rows;

	len_cols = cols;
	// len_rows = rows;
	tmp = map;
	rows = 0;
	while(tmp && tmp->line && i <= len_cols)
	{
		i = 0;
		cols = 0;
		while (tmp && tmp->line[i] != '\0')
		{
			map_arr[rows][cols] = tmp->line[i];
			printf("larray es %c\n", map_arr[rows][cols]);
			i++;
			cols++;
		}
		map_arr[rows][cols] = '\0';
		tmp = tmp->next;
		rows++;
	}
}

void    print_list (t_map *map)
{
    t_map	*temp_a;
    temp_a = map;
    while (temp_a)
    {
        printf("valor en lista:%s\n", temp_a->line);
        temp_a = temp_a->next;
    }
    printf("----------------------------------------\n");
}