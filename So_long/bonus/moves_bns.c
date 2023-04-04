#include "../mlx/mlx.h"
#include "so_long.h"
#include "libft.h"

static void	ft_move_w(t_map *map);
static void	ft_move_d(t_map *map);
static void	ft_move_a(t_map *map);
static void	ft_move_s(t_map *map);
static void	put_string(t_map *map);

static void	ft_move_w(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		put_string(map);
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start - 1][map->end] != '1')
	{
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, map->y);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y - 32));
		map->start -= 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_s(t_map *map)
{	
	if (map->map_array[map->start][map->end] == 'E')
	{
		put_string(map);
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start + 1][map->end] != '1')
	{
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, map->y);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y + 32));
		map->start += 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_d(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		put_string(map);
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start][map->end + 1] != '1')
	{
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x + 32), map->y);
		map->end += 1;
	}
	else
		write(1, "You hit a wall\n", 15);
}

static void	ft_move_a(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		put_string(map);
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start][map->end - 1] != '1')
	{
		put_string(map);
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x - 32), map->y);
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
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win_ptr);
		free(map);
		exit (0);
	}
	if (keycode == 13)
		ft_move_w(map);
	if (keycode == 2)
		ft_move_d(map);
	if (keycode == 0)
		ft_move_a(map);
	if (keycode == 1)
		ft_move_s(map);
	// write(1, moves_str, ft_strlen(moves_str));
	// if (moves_str)
	// 	free(moves_str);
	// write(1, "\n", 1);
	// free(moves_str);
	return (0);
}

static void	put_string(t_map *map)
{
	char	*moves_str;

	moves_str = ft_itoa(map->moves);
	map->moves++;
	mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,map->img_black, 0, 196);
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr, 20, 210, 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr, 80, 210, 0xFFFFFF, moves_str);
	free(moves_str);
}