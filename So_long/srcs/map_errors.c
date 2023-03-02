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

void    ft_openmap(char **argv)
{
         
}