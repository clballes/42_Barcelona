/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:58 by clballes          #+#    #+#             */
/*   Updated: 2023/04/04 15:07:00 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include "libft.h"

static void	ft_move_w(t_map *map);
static void	ft_move_d(t_map *map);
static void	ft_move_a(t_map *map);
static void	ft_move_s(t_map *map);

static void	ft_move_w(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E' && map->collective == 0)
		close_click(map);
	if (map->map_array[map->start][map->end] == 'C')
	{
		map->collective--;
		map->map_array[map->start][map->end] = '0';
	}
	if (map->map_array[map->start - 1][map->end] != '1')
	{
		ft_moves(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, map->y);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y - 32));
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->start -= 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_s(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E' && map->collective == 0)
		close_click(map);
	if (map->map_array[map->start][map->end] == 'C')
	{
		map->collective--;
		map->map_array[map->start][map->end] = '0';
	}
	if (map->map_array[map->start + 1][map->end] != '1')
	{
		ft_moves(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, map->y);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y + 32));
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->start += 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_d(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E' && map->collective == 0)
		close_click(map);
	if (map->map_array[map->start][map->end] == 'C')
	{
		map->collective--;
		map->map_array[map->start][map->end] = '0';
	}
	if (map->map_array[map->start][map->end + 1] != '1')
	{
		ft_moves(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x + 32), map->y);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->end += 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_a(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E' && map->collective == 0)
		close_click(map);
	if (map->map_array[map->start][map->end] == 'C')
	{
		map->collective--;
		map->map_array[map->start][map->end] = '0';
	}
	if (map->map_array[map->start][map->end - 1] != '1')
	{
		ft_moves(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x - 32), map->y);
		if (map->map_array[map->start][map->end] == 'E')
			mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
				map->img_exit, map->x, map->y);
		map->end -= 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

int	key_hook(int keycode, t_map *map)
{
	map->y = (map->start) * 32;
	map->x = (map->end) * 32;
	if (keycode == 53)
		close_click(map);
	if (keycode == 13)
		ft_move_w(map);
	if (keycode == 2)
		ft_move_d(map);
	if (keycode == 0)
		ft_move_a(map);
	if (keycode == 1)
		ft_move_s(map);
	return (0);
}
