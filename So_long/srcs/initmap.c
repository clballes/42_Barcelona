#include <mlx.h>
#include "so_long.h"

static int close_click();
static int	key_hook(int keycode, t_map *map, char **map_arr);
// static void	ft_move_w(t_map *map, char **map_arr);

static int close_click()
{
		exit (0);
}

// static void	ft_move_w(t_map *map, char **map_arr)
// {
// 	int	i;
// 	int j;
// 	i = 4; //position of C
// 	j = 1; //position of C
// 	map_arr = NULL;
// 	printf("holaaaaa\n");
// 	mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);
// 	// mlx_destroy_image(map->mlx_ptr, map->img_p);
// }

static int	key_hook(int keycode, t_map *map, char **map_arr)
{
	map_arr = NULL;
	printf("mlx_ptr: %p\n", map->mlx_ptr);
	printf("mlx_win_ptr: %p\n", map->mlx_win_ptr);
	if (keycode == 13) //53 for esc
	{
		mlx_clear_window(map->mlx_ptr, map->mlx_win_ptr);	
		// exit (0);
	}
	// if (keycode == 13) //soy una W
	// {
	// 	printf("soy una W!\n"); //handle event perq el player vagi un cap adalt
	// 	ft_move_w(map, map_arr);
	// 	// ft_newimage(map, map_arr);
	// 	printf("les cols son %d\n", map->cols);

	// }
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
	printf("mlx_ptr IN THE MAIN: %p\n", map->mlx_ptr);
	printf("mlx_win_ptr IN THE MAIN: %p\n", map->mlx_win_ptr);
	init_image(map);
	printwind(map, map_arr);
	mlx_key_hook(map->mlx_win_ptr, key_hook, &map); //keyhook esc and move player el pointer es una direccio diferent dunnowhy algun problema de memoria dec tenir
	mlx_hook(map->mlx_win_ptr, 17,  1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}