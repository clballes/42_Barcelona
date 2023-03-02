/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:02:53 by clballes          #+#    #+#             */
/*   Updated: 2023/02/23 16:02:54 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_checkber(char **argv)
{
    int i;
    i = 0;
    while (*argv[1] && argv[1][i])
    {
        if (argv[1][i] == '.')
        {
            i++;
            if (argv[1][i] == 'b' && argv[1][i + 1] == 'e' && argv[1][i + 2] == 'r')
            {
                printf("holaaaa\n");
                ft_openmap(&argv[1]);
            }
            else
                printf("Not ber extension, try an other map!\n");
        }
        i++;
    }
}

int    ft_openmap(char **argv) //USAR GETNEXT LINE
{
    int fd;
    char *buf;
    size_t num_bytes;

    fd = open("/Users/clballes/Desktop/42Barcelona/So_long/maps", O_RDONLY);
    if (fd == -1)
        printf("ERRROR OPENINNG\n");
    else
    {
        num_bytes = read(fd, buf, 5);
        if (num_bytes == 0)
            printf("Archivo vacio\n");
        else
            printf("el num de bytes es: %zu\n", num_bytes);
    }
        
}