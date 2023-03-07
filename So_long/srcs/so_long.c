/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:14 by clballes          #+#    #+#             */
/*   Updated: 2023/03/02 12:52:15 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int main(int argc, char **argv)
{
    if (argc > 1 && *argv[1])
        ft_checkber(argv);
    else
        printf("missing map!\n");
}

void    ft_openmap(char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        printf("ERRROR OPENINNG\n");
    else
    {
        line = get_next_line(fd);
        printf("la line es: %s\n", line);
    }
}