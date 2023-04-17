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
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char			**map_array;
	int				rows;
	int				cols;
	int				weight;
	int				next_row;
	int				next_col;
	int				coll;
	int				collective;
	int				x;
	int				y;
	int				start;
	int				end;
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	void			*img_player;
	void			*img_black;
	void			*img_exit;
	void			*img_coll;
	void			*img_1;
	void			*img_0;
	int				delta_row[4];
	int				delta_col[4];
	int				moves;
	int				i;
	int				stop;
	char			*map_unid;
}					t_map;

//functions create check map
int		ft_open_ber(char **argv);
void	ft_openmap(char **argv);
void	ft_arraymap(t_map *map);
void	check_map_walls(t_map *map, int rows, int cols);
int		ft_strncmp_long(char c, char *s2);
void	has_valid_path(t_map *map, char **cy_map_arr);
void	check_len(int cols, char *line);
void	init_delta(t_map *map);

//print functions
void	write_error(char error);
//minilibx functions handle
int		open_window(t_map *map);
void	init_image(t_map *map);
void	printwind(t_map *map);
int		key_hook(int keycode, t_map *map);
int		close_click(t_map *map);
int		show_str(t_map *map);
void	update_image(t_map *map);
void	ft_moves(t_map *map);
int		close_cross(t_map *map);
#endif
