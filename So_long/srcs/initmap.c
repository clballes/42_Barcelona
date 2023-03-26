#include <mlx.h>
#include "so_long.h"

static int esc_windw(int keypress);
static int close_click();


static int close_click()
{
		exit (0);
}

static	int esc_windw(int keypress) //press esc and close window
{
	if (keypress == 53)
		exit (0);
	return (0);
}

int open_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, 1920, 1080, "So long!!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	mlx_hook(map->mlx_win_ptr, 17,  1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_hook(map->mlx_win_ptr, 2, 1L << 0, esc_windw, &map); //esc closing
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}