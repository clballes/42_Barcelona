/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:23 by clballes          #+#    #+#             */
/*   Updated: 2023/03/22 12:32:53 by clballes         ###   ########.fr       */
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
	char			*line;
	char			*line2;
	int				rows;
	int				cols;
	int				coll;
	int				start;
	int				end;
	struct s_map	*next;
	void			*mlx_ptr;
	void			*mlx_win_ptr;
}					t_map;
void	ft_open_ber(char **argv);
void	ft_arraymap(t_map *map);
void	check_map_walls(char **map_arr, int rows, int cols);
int		ft_strncmp_long(char c, char *s2);
void	has_valid_path(t_map *map, char **cy_map_arr, char **map_arr);
//list functions
t_map	*ft_lstnew_long(void	*content);
void	ft_lstadd_back_long(t_map **lst, t_map *new);
t_map	*ft_lstlast_long(t_map *lst);

//print functions
void	print_list(t_map *map);
void	write_error(void);
//windoelin
int open_window(t_map *map, char **map_arr);

#endif
