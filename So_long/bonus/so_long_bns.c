/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:14 by clballes          #+#    #+#             */
/*   Updated: 2023/03/07 12:11:46 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

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

void	init_image(t_map *map)
{
	int	h;
	int	w;

	h = 32;
	w = 32;
	map->img_1 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/shark.xpm", &w, &h);
	map->img_0 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave.xpm", &w, &h);
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/surfista.xpm", &w, &h);
	map->img_exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/palmtree.xpm", &w, &h);
	map->img_coll = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/van.xpm", &w, &h);
	map->sprites[0] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr1.xpm", &w, &h);
	map->sprites[1] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr2.xpm", &w, &h);
	map->sprites[2] = mlx_xpm_file_to_image(map->mlx_ptr,
			"./png/wave_spr3.xpm", &w, &h);
}

void	init_delta(t_map *map)
{
	int	delta_row[4];
	int	delta_col[4];
	int	i;

	delta_row[0] = -1;
	delta_row[1] = 0;
	delta_row[2] = 1;
	delta_row[3] = 0;
	delta_col[0] = 0;
	delta_col[1] = 1;
	delta_col[2] = 0;
	delta_col[3] = -1;
	i = 0;
	while (i < 4)
	{
		map->delta_row[i] = delta_row[i];
		map->delta_col[i] = delta_col[i];
		i++;
	}
}
