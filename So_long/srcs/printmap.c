#include <mlx.h>
#include "so_long.h"
static void    print_img(t_map *map, char c, int x, int y);

void    init_image(t_map *map)
{
    int h;
    int w;
    
    h = 100;
	w = 100;
    map->img_1 = mlx_xpm_file_to_image(map->mlx_ptr, "./png/shark2.xpm", &w, &h);
    map->img_0 = mlx_xpm_file_to_image(map->mlx_ptr, "./png/wave.xpm", &w, &h);
    map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, "./png/surfista.xpm", &w, &h);
    map->img_exit = mlx_xpm_file_to_image(map->mlx_ptr, "./png/palmtree.xpm", &w, &h);
    map->img_coll = mlx_xpm_file_to_image(map->mlx_ptr, "./png/van.xpm", &w, &h);
    printf("mlx_ptr IN THE print: %p\n", map->mlx_ptr);
	printf("mlx_win_ptr IN THE print: %p\n", map->mlx_win_ptr);
}

void    printwind(t_map *map, char **map_arr)
{
    int i;
	int j;
	int	x;
	int y;
	
	i = 0;
	y = 0;
	while (**map_arr && i <= (map->rows - 1))
	{
		j = 0;
		x = 0;
		y += 50;
		while (j <= (map->cols - 1))
		{
			print_img(map, map_arr[i][j], x, y);
			x += 50;
			j++;
		}
		i++;
	}
    printf("mlx_ptr IN THE printWIND: %p\n", map->mlx_ptr);
	printf("mlx_win_ptr IN THE printWIND: %p\n", map->mlx_win_ptr);

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

