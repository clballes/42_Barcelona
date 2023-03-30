#include <mlx.h>
#include "so_long.h"

static int close_click();
static int	key_hook(int keycode, t_map *map);
static void	ft_move_w(t_map *map);

static int close_click()
{
		exit (0);
}

static void	ft_move_w(t_map *map)
{
	int	x;
	int y;

	x = 50; //position player on the map
	y = 250; //position player on the map
	mlx_destroy_image(map->mlx_ptr, map->img_player);
	mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_0, x, y);
	mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, map->img_player, x, (y - 50));
}

static int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 13) 
		ft_move_w(map);
	// else if (keycode == 2)
	// 	printf("Soy una d!\n"); //soc una D
	// else if (keycode == 1) //soc una S
	// 	printf("Soy una S!\n");
	// else if (keycode == 0) //soy una a
	// 	printf("Soy una A!\n");
	return (0);
}

int open_window(t_map *map, char **map_arr)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	int x = (map->cols * 50);
	int y = ((map->rows + 1) * 50);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, x, y, "So long!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	init_image(map);
	printwind(map, map_arr);
	mlx_key_hook(map->mlx_win_ptr, key_hook, map); //keyhook esc and move player el pointer es una direccio diferent dunnowhy algun problema de memoria dec tenir
	mlx_hook(map->mlx_win_ptr, 17,  1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}