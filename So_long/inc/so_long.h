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
#define WIDTH 640
#define HEIGHT 480
#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32
#define NUM_FRAMES 3

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char			**map_array;
	int				rows;
	int				cols;
	int				next_row;
	int				next_col;
	int				coll;
	int				x;
	int 			y;
	int				start;
	int				end;
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	void			*img_player;
	void			*img_black;
	void			*img_exit;
	void			*img_coll;
	void			*img_1;
	void			*sprites[NUM_FRAMES];
	void			*img_0;
	int				delta_row[4];
	int				delta_col[4];
	int				moves;
	int				frame;
	int				*put_x;
	int				*put_y;
	int				i;
	int				stop;
}					t_map;
typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

//functions create check map
int		ft_open_ber(char **argv);
void	ft_openmap(char **argv);
void	ft_arraymap(t_map *map, t_line *temp);
void	check_map_walls(t_map *map, int rows, int cols);
int		ft_strncmp_long(char c, char *s2);
void	has_valid_path(t_map *map, char **cy_map_arr);
void	check_len(int cols, t_line *temp);
void	init_delta(t_map *map);
//list functions
t_line	*ft_lstnew_long(void	*content);
void	ft_lstadd_back_long(t_line **lst, t_line *new);
t_line	*ft_lstlast_long(t_line *lst);
//print functions
void	write_error(char error);
//minilibx functions handle
int		open_window(t_map *map);
void	init_image(t_map *map);
void    printwind(t_map *map);
int		key_hook(int keycode, t_map *map);
int		close_click();
int		show_str(t_map *map);
void	update_image(t_map *map);
//bonus functions
int		spritehook(void *param);
void	put_string(t_map *map);
void	print_x(t_map *map);
#endif
