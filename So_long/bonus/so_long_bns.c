/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:14 by clballes          #+#    #+#             */
/*   Updated: 2023/04/04 15:10:32 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"
#include "libft.h"

static void	put_img_player(t_map *map);

int	main(int argc, char **argv)
{
	if (argc > 1 && *argv[1])
	{
		if (ft_open_ber(argv) == 1)
			ft_openmap(argv);
		else
			write_error('0');
	}
	else
		write_error('5');
}

void	init_image(t_map *map)
{
	int	h;
	int	w;

	h = 32;
	w = 32;
	map->img_1 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/shark.xpm", &w, &h);
	map->img_0 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave.xpm", &w, &h);
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/surfista.xpm", &w, &h);
	map->img_exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/palmtree.xpm", &w, &h);
	map->img_coll = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/van.xpm", &w, &h);
	map->sprites[0] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr1.xpm", &w, &h);
	map->sprites[1] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr2.xpm", &w, &h);
	map->sprites[2] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr3.xpm", &w, &h);
	map->img_black = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/black.xpm", &w, &h);
}

void	init_delta(t_map *map)
{
	int	delta_row[4];
	int	delta_col[4];
	int	i;

	map->moves = 1;
	delta_row[0] = -1;
	delta_row[1] = 0;
	delta_row[2] = 1;
	delta_row[3] = 0;
	delta_col[0] = 0;
	delta_col[1] = 1;
	delta_col[2] = 0;
	delta_col[3] = -1;
	i = 0;
	while (i < 4)
	{
		map->delta_row[i] = delta_row[i];
		map->delta_col[i] = delta_col[i];
		i++;
	}
}

int	spritehook(void *param)
{
	t_map	*map;
	int		i;

	map = (t_map *)param;
	i = 0;
	map->frame = (map->frame + 1) % NUM_FRAMES;
	while (i <= map->i)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->sprites[map->frame], map->put_x[i], map->put_y[i]);
		printf("el map i es %d\n", map->i);
		// printf("array de x es %d\n", map->put_x[i]);
		// printf("array de y es %d\n", map->put_y[i]);
		i++;
	}
	put_img_player(map);
	usleep(100000);
	return (0);
}

static void	put_img_player(t_map *map)
{
	if (map->stop == 3) //move D
	{

		if (map->map_array[map->start][map->end - 1] == 'C' || map->map_array[map->start][map->end - 1] == 'P')
		{
			map->i++;
			map->put_x[map->i] = map->x;
			map->put_y[map->i] = map->y;
		}
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x + 32), map->y);
	}
	else if (map->stop == 4)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x - 32), map->y);
	}
	else if (map->stop == 5)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y + 32));
	}
	else if (map->stop == 6)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y - 32));
	}
	else if (map->stop == 8)
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x), map->y);
}

void	put_string(t_map *map)
{
	char	*moves_str;

	moves_str = ft_itoa(map->moves);
	map->moves++;
	mlx_put_image_to_window (map->mlx_ptr,
		map->mlx_win_ptr, map->img_black, 0, 196);
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		20, 210, 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		80, 210, 0xFFFFFF, moves_str);
	free(moves_str);
}