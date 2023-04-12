/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:14 by clballes          #+#    #+#             */
/*   Updated: 2023/04/11 16:11:03 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
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
		map->mlx_win_ptr, map->img_black, 0, 196);
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		20, 210, 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx_ptr, map->mlx_win_ptr,
		80, 210, 0xFFFFFF, moves_str);
	free(moves_str);
}
