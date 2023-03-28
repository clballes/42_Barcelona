#include <mlx.h>
#include "so_long.h"

static int esc_windw(int keypress);
static int close_click();
static int putimage(t_map *map, char **map_arr);
// // static int	key_hook(int keycode, t_map *map);

static int putimage(t_map *map, char **map_arr)
{
	void	*img;
	int h = 100;
	int w = 100;
	int i = 0;
	int j = 0;
	int	x = 0;
	int y = 0;

	while (**map_arr && i <= (map->rows - 3))
	{
		j = 0;
		while (j <= (map->cols - 1))
		{
			if (map_arr[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(map->mlx_ptr, "./png/shark2.xpm", &w, &h);
				mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, img, x, (y + 50)); //row
			}
			else if (map_arr[i][j] == '0')
			{
				printf("quepassaaaa\n");
				img = mlx_xpm_file_to_image(map->mlx_ptr, "./png/surfista.xpm", &w, &h);
				mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, img, (x + 50), (y + 50)); //row
			}
			x += 50;
			j++;
		}
		i++;
	}
	return (1);
}

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

// static int	key_hook(int keycode, t_map *map)
// {
// 	if (keycode == 13) //soy una W
// 		printf("soy una W!\n"); //handle event perq el player vagi un cap adalt
// 	else if (keycode == 2)
// 		printf("Soy una d!\n"); //soc una D
// 	else if (keycode == 1) //soc una S
// 		printf("Soy una S!\n");
// 	else if (keycode == 0) //soy una a
// 		printf("Soy una A!\n");
// 	printf("les cols son%d\n", map->cols);
// 	return (0);
// }

int open_window(t_map *map, char **map_arr)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	int x = (map->cols * 50);
	int y = ((map->rows - 1) * 50);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, x, y, "So long!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	putimage(map, map_arr);
	mlx_hook(map->mlx_win_ptr, 17,  1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_hook(map->mlx_win_ptr, 2, 1L << 0, esc_windw, &map); //esc closing
	// mlx_key_hook(map->mlx_win_ptr, key_hook, &map); //keyhook 
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}