#include "../mlx/mlx.h"
#include "so_long.h"
#include "libft.h"

static void	ft_move_w(t_map *map);
static void	ft_move_d(t_map *map);
static void	ft_move_a(t_map *map);
static void	ft_move_s(t_map *map);

static void	ft_move_w(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start - 1][map->end] != '1')
	{
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_player, map->x, (map->y - 32));
		map->start -= 1;
	}
	else
		printf("you cannot do thatttt W\n");
}

static void	ft_move_s(t_map *map)
{	
	if (map->map_array[map->start][map->end] == 'E')
	{
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start + 1][map->end] != '1')
	{
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_0, map->x, map->y);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_player, map->x, (map->y + 32));
		map->start += 1;
	}
	else
		printf("you cannot do thatttt W\n");
}

static void	ft_move_d(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start][map->end + 1] != '1')
	{
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_player, (map->x + 32), map->y);
		map->end += 1;
	}
	else
		printf("you cannot do thatttt en la D\n");
}

static void	ft_move_a(t_map *map)
{
	if (map->map_array[map->start][map->end] == 'E')
	{
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
		exit (0);
	}
	else if (map->map_array[map->start][map->end - 1] != '1')
	{
		mlx_destroy_image(map->mlx_ptr, map->img_player);
		init_image(map);
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_0, map->x, (map->y));
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_player, (map->x - 32), map->y);
		map->end -= 1;
	}
	else
		printf("you cannot do thatttt en la D\n");
}

int	key_hook(int keycode, t_map *map)
{
	map->y = (map->start + 1) * 32;
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
	char *moves; 
	moves = ft_itoa(map->moves);
	write(1, moves, ft_strlen(moves));
	if (moves)
		free(moves);
	write(1, "\n", 1);
	map->moves++;
	return (0);
}
	// mlx_string_put(map->mlx_ptr, map->mlx_win_ptr, 10, 10, 0xFFFFFF, "Moves: "); // Display the label "Moves:"
	// char *moves_str = ft_itoa(map->moves);
	// mlx_string_put(map->mlx_ptr, map->mlx_win_ptr, 70, 10, 0xFFFFFF, moves_str); // Display the value of moves
	// free(moves_str); // Free the memory allocated by ft_itoa()