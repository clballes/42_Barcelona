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

static void	ft_arraymap(t_map *map, int rows);
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
	t_map	*map;
	t_map	*temp;

	map = NULL;
	temp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("ERRROR OPENINNG\n");
	else
	{
		map = ft_createmap(map, temp, fd);
		if (map == 0)
			printf("the map is empty!\n");
	}
}

t_map	*ft_createmap(t_map *map, t_map *temp, int fd)
{
	char	*line;
	int		rows;
	int		cols;

	rows = 0;
	line = get_next_line(fd);
	temp = ft_lstnew_long(line);
	cols = ft_strlen(line);
	rows++;
	if (line)
	{
		while (line != NULL)
		{
			ft_lstadd_back_long(&map, temp);
			line = get_next_line(fd);
			temp = ft_lstnew_long(line);
			rows++;
		}
		ft_arraymap(map, rows);
	}
	else
		return (0);
	return (map);
}

static void	ft_arraymap(t_map *map, int rows)
{
	char	**map_arr;
	int		i;
	t_map	*tmp;

	i = 0;
	tmp = map;
	map_arr = malloc(sizeof(char *) * (rows));	
	while(i < rows && tmp)
	{
		map_arr[i] = tmp->line;
		// printf("el print del mpa arr es %s\n",  map_arr[i]);
		i++;
		tmp = tmp->next;
	}
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