/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:08:30 by clballes          #+#    #+#             */
/*   Updated: 2023/04/04 15:09:51 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

static void	ft_move_w(t_map *map);
static void	ft_move_d(t_map *map);
static void	ft_move_a(t_map *map);
static void	ft_move_s(t_map *map);

static void	ft_move_w(t_map *map)
{
	check_move_collec(map);
	if (map->map_array[map->start - 1][map->end] != '1')
	{
		map->stop = 6;
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->start -= 1;
	}
	else
	{
		write(1, "You hit a wall\n", 15);
		map->stop = 8;
	}
}

static void	ft_move_s(t_map *map)
{	
	check_move_collec(map);
	if (map->map_array[map->start + 1][map->end] != '1')
	{
		map->stop = 5;
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->start += 1;
	}
	else
	{
		write(1, "You hit a wall\n", 15);
		map->stop = 8;
	}
}

static void	ft_move_d(t_map *map)
{
	check_move_collec(map);
	if (map->map_array[map->start][map->end + 1] != '1')
	{
		map->stop = 3;
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->end += 1;
	}
	else
	{
		write(1, "You hit a wall\n", 15);
		map->stop = 8;
	}
}

static void	ft_move_a(t_map *map)
{
	check_move_collec(map);
	if (map->map_array[map->start][map->end - 1] != '1')
	{
		map->stop = 4;
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->end -= 1;
	}
	else
	{
		write(1, "You hit a wall\n", 15);
		map->stop = 8;
	}
}

int	key_hook(int keycode, t_map *map)
{
	map->y = (map->start) * 32;
	map->x = (map->end) * 32;
	map->stop = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win_ptr);
		free(map->map_array);
		free(map->put_x);
		free(map->put_y);
		free(map);
		exit (0);
	}
	else if (keycode == 13)
		ft_move_w(map);
	else if (keycode == 2)
		ft_move_d(map);
	else if (keycode == 0)
		ft_move_a(map);
	else if (keycode == 1)
		ft_move_s(map);
	else
		map->stop = 8;
	return (0);
}
