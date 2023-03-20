/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:23 by clballes          #+#    #+#             */
/*   Updated: 2023/03/07 12:16:44 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
    char                    *line;
    int                     rows;
    int                     cols;
	struct s_map            *next;
}                           t_map;
void	ft_open_ber(char **argv);
void	ft_arraymap(t_map *map);
void	check_map_walls(char **map_arr, int rows, int cols);
int     ft_strncmp_long(char c, char *s2);
int     has_valid_path(char **map_arr, t_map *map);
int     backtrack(char **map, int row, int col, int num_rows, int num_cols);


//list functions
t_map	*ft_lstnew_long(void	*content);
void	ft_lstadd_back_long(t_map **lst, t_map *new);
t_map	*ft_lstlast_long(t_map *lst);

//print functions
void    print_list (t_map *map);
void	write_error(void);

#endif
