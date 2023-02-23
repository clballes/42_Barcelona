/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:33:29 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:57:00 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "libft.h"


void	ft_check(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = 0;
		if (argv[j][i] == '\0')
			write_error();
		if (argv[j][i] == '0' && (argv[j][1] >= '0' && argv[j][1] <= '9'))
			write_error();
		while (argv[j][i])
		{
			check2(argv, i, j);
			i++;
		}
		j++;
	}
	j = 1;
	ft_comparedigit(argv, argc, j);
	ft_maxmin_int(argv, argc, j);
}

void	check2(char **argv, int i, int j)
{
	if (argv[j][i] == '-')
	{
		i++;
		if (argv[j][i] == '-' || argv[j][i] == '0' || argv[j][i] == '\0')
			write_error();
	}
	else if (argv[j][i] >= '0' && argv[j][i] <= '9')
	{
		i++;
		if (argv[j][i] == '-')
			write_error();
	}
	else
		write_error();
}

void	ft_comparedigit(char **argv, int argc, int j)
{
	int	i;

	while (j < argc)
	{
		i = 1 + j;
		while (argv[i])
		{
			if (ft_strncmp(argv[j], argv[i], 11) == 0)
				write_error();
			i++;
		}
		j++;
	}
}

void	ft_maxmin_int(char **argv, int argc, int j)
{
	while (argv[j] && j < argc)
	{
		if (ft_strlen(argv[j]) > 11)
			write_error();
		if (argv[j][0] == '-' && (ft_strlen(argv[j]) == 11))
		{
			if (ft_strncmp(argv[j], "-2147483648", 11) > 0)
				write_error();
		}
		j++;
	}
	j = 1;
	while (argv[j] && j < argc && argv[j][0] != '-')
	{
		if (ft_strlen(argv[j]) == 11)
			write_error();
		if (ft_strlen(argv[j]) == 10)
		{
			if (ft_strncmp(argv[j], "2147483647", 11) > 0)
				write_error();
		}
		j++;
	}
}

void	write_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
