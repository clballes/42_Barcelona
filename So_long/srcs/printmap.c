#include "../mlx/mlx.h"
#include "so_long.h"

static void    print_img(t_map *map, char c, int x, int y);
static void		update_image(t_map *map);

int close_click()
{
	exit (0);
}

static void update_image(t_map *map)
{
    map->frame = (map->frame + 1) % NUM_FRAMES;
    mlx_put_image_to_window(map->mlx_ptr, map->mlx_win_ptr, map->sprites[map->frame],0, 0);
}

int open_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	int x = (map->cols * 32);
	int y = ((map->rows + 1) * 32);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, x, y, "So long!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	init_image(map);
	printwind(map);
	mlx_key_hook(map->mlx_win_ptr, key_hook, map); //keyhook esc and move player el pointer es una direccio diferent dunnowhy algun problema de memoria dec tenir
	mlx_hook(map->mlx_win_ptr, 17, 1L << 0, close_click, NULL); //closing and exiting with the cros corrrect way
	mlx_loop_hook(map->mlx_ptr, (void*)update_image, map);
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}

void    init_image(t_map *map)
{
    int h;
    int w;

    h = 32;

	w = 32;
    map->img_1 = mlx_xpm_file_to_image(map->mlx_ptr, "./png/shark.xpm", &w, &h);
    map->img_0 = mlx_xpm_file_to_image(map->mlx_ptr, "./png/wave.xpm", &w, &h);
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, "./png/surfista.xpm", &w, &h);
    map->img_exit = mlx_xpm_file_to_image(map->mlx_ptr, "./png/palmtree.xpm", &w, &h);
    map->img_coll = mlx_xpm_file_to_image(map->mlx_ptr, "./png/van.xpm", &w, &h);
    map->sprites[0] = mlx_xpm_file_to_image(map->mlx_ptr, "./png/wave2.0.xpm", &w, &h);
    map->sprites[1] = mlx_xpm_file_to_image(map->mlx_ptr, "./png/wave.xpm", &w, &h);
}

void    printwind(t_map *map)
{
    int i;
	int j;
	int	x;
	int y;
	
	i = 0;
	y = 0;
	while (map->map_array && i <= (map->rows - 1))
	{
		j = 0;
		x = 0;
		y += 32;
		while (j <= (map->cols - 1))
		{
			print_img(map, map->map_array[i][j], x, y);
			x += 32;
			j++;
		}
		i++;
	}
}

static void    print_img(t_map *map, char c, int x, int y)
{
    void    *img;

    img = NULL;
    if (c == '1')
        img = map->img_1;
    else if (c == '0')
        img = map->img_0;
    else if (c == 'C')
        img = map->img_coll;
    else if (c == 'P')
        img = map->img_player;
    else if (c == 'E')
        img = map->img_exit;
    mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, img, x, y);
}
