/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funciones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:04:56 by clballes          #+#    #+#             */
/*   Updated: 2022/11/04 18:18:47 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	take_numbers(int argc, char **argv);
int	take_numbers(int argc, char **argv)
{
	int j;
	int i;
	int cont;
	char arr[0];	
	j = 1;
	arr[0] = *argv[j];
	cont = 0;
	printf("hola");
	while (argv[j] && argc)
	{
		printf("hola");
		i = 0;
		while (arr[cont])
		{
			arr[cont] = argv[j][i];
			if (argv[j][i + 1] == '\0')
				return (1);
			i++;
		}
		cont++;
		j++;
	}
	return (0);
}
