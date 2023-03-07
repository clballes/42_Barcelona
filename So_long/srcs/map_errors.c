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
	char	*line;
	int		fd;
	// t_game	map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("ERRROR OPENINNG\n");
	else
	{
			line = get_next_line(fd);
			printf("holaaaa la line es %s\n", line);
			// map = ft_lstnew(line);
	}
}
