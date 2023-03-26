#include <mlx.h>
#include "so_long.h"

static int esc_windw(int keypress);
static int close_click();
static int putimage(t_map *map);
static int	key_hook(int keycode, t_map *map);


static int putimage(t_map *map)
{
	char	*filename;
	int		img_width;
	int		img_height;
	void	*img;

	filename = "./png/surfista.xpm";
	img = mlx_xpm_file_to_image(map->mlx_ptr, filename, &img_width, &img_height);
	if (img  == NULL)
		printf("image has failes loading!\n");
	mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, img, 1, 2);
	return 1;
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

static int	key_hook(int keycode, t_map *map)
{
	if (keycode == 13) //soy una W
		printf("soy una W!\n"); //handle event perq el player vagi un cap adalt
	else if (keycode == 2)
		printf("Soy una d!\n"); //soc una D
	else if (keycode == 1) //soc una S
		printf("Soy una S!\n");
	else if (keycode == 0) //soy una a
		printf("Soy una A!\n");
	printf("%d\n", map->cols);
	return (0);
}

int open_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, 500, 500, "So long!!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	putimage(map);
	mlx_hook(map->mlx_win_ptr, 17,  1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_hook(map->mlx_win_ptr, 2, 1L << 0, esc_windw, &map); //esc closing
	mlx_key_hook(map->mlx_win_ptr, key_hook, &map); //keyhook 
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}