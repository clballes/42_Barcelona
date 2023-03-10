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
// #include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && *argv[1])
		ft_open_ber(argv);
	else
		write_error();
}
