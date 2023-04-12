/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:10:00 by clballes          #+#    #+#             */
/*   Updated: 2023/04/11 16:14:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include "libft.h"

static void	print_img(t_map *map, char c, int x, int y);
static void	ft_loop(t_map *map, int x, int y);

int	close_click(void)
{
	system("leaks so_long_bonus");
	exit (0);
}

int	open_window(t_map *map)
{
	int	x;
	int	y;

	x = (map->cols * 32);
	y = ((map->rows + 1) * 32);
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (0);
	map->mlx_win_ptr = mlx_new_window(map->mlx_ptr, x, y, "So long!");
	if (map->mlx_win_ptr == NULL)
	{
		free(map->mlx_win_ptr);
		return (0);
	}
	init_image(map);
	printwind(map);
	mlx_key_hook(map->mlx_win_ptr,
		key_hook, map);
	mlx_hook(map->mlx_win_ptr,
		17, 1L << 0, close_click, NULL);
	mlx_loop(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}

void	printwind(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map->map_array && i <= (map->rows - 1))
	{
		j = 0;
		x = 0;
		while (j <= (map->cols - 1))
		{
			print_img(map, map->map_array[i][j], x, y);
			x += 32;
			j++;
		}
		i++;
		y += 32;
	}
}

static void	print_img(t_map *map, char c, int x, int y)
{
	void	*img;

	img = NULL;
	if (c != '0')
	{
		if (c == '1')
			img = map->img_1;
		else if (c == 'C')
			img = map->img_coll;
		else if (c == 'P')
			img = map->img_player;
		else if (c == 'E')
			img = map->img_exit;
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr, img, x, y);
	}
	else
		ft_loop(map, x, y);
}

static void	ft_loop(t_map *map, int x, int y)
{
	if (x && y)
	{
		if (!map->put_x && !map->put_y)
		{
			map->put_x = malloc(sizeof(int) * (map->rows * map->cols));
			map->put_y = malloc(sizeof(int) * (map->rows * map->cols));
		}
		map->put_x[map->i] = x;
		map->put_y[map->i] = y;
		map->i++;
	}
	map->stop = 1;
	mlx_loop_hook(map->mlx_ptr, spritehook, map);
}
