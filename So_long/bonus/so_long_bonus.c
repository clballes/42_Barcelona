/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:14 by clballes          #+#    #+#             */
/*   Updated: 2023/04/14 12:08:00 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"
#include "libft.h"

static void	put_img_player(t_map *map);

int	main(int argc, char **argv)
{
	if (argc > 1 && *argv[1])
	{
		if (ft_open_ber(argv) == 1)
			ft_openmap(argv);
		else
			write_error('0');
	}
	else
		write_error('5');
}

int	spritehook(void *param)
{
	t_map	*map;
	int		i;

	map = (t_map *)param;
	i = 0;
	map->frame = (map->frame + 1) % NUM_FRAMES;
	while (i < map->i)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->sprites[map->frame], map->put_x[i], map->put_y[i]);
		i++;
	}
	put_img_player(map);
	usleep(150000);
	return (0);
}

static void	put_img_player(t_map *map)
{
	if (map->stop == 3)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x + 32), map->y);
	}
	else if (map->stop == 4)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x - 32), map->y);
	}
	else if (map->stop == 5)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y + 32));
	}
	else if (map->stop == 6)
	{
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, map->x, (map->y - 32));
	}
	else if (map->stop == 8)
		mlx_put_image_to_window (map->mlx_ptr, map->mlx_win_ptr,
			map->img_player, (map->x), map->y);
}

void	put_string(t_map *map)
{
	char	*moves_str;

	moves_str = ft_itoa(map->moves);
	map->moves++;
	mlx_put_image_to_window (map->mlx_ptr,
		map->mlx_win_ptr, map->img_black, 32, (map->rows * 32));
	mlx_put_image_to_window (map->mlx_ptr,
		map->mlx_win_ptr, map->img_black, 64, (map->rows * 32));
	mlx_put_image_to_window (map->mlx_ptr,
		map->mlx_win_ptr, map->img_black, 96, (map->rows * 32));
	mlx_put_image_to_window (map->mlx_ptr,
		map->mlx_win_ptr, map->img_black, 0, (map->rows * 32));
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		20, (map->weight - 15), 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		80, (map->weight - 15), 0xFFFFFF, moves_str);
	free(moves_str);
}

int	close_cross(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win_ptr);
	free(map->map_array);
	free(map->put_x);
	free(map->put_y);
	free(map);
	exit (0);
}
