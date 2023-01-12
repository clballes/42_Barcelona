/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:51:17 by clballes          #+#    #+#             */
/*   Updated: 2022/11/04 18:17:54 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int argc, char **argv)
{
	int				 	i;
	t_push_list *stack;
	t_push_list *stack_b;

	stack = NULL;
	stack_b = NULL;
	if (argc == 1)
		write_error();
	else
	{
		ft_check(argc, argv);
		i = 1;
	  	while(argv[i])
		{
			take_numbers(&stack, ft_atoi(argv[i]));
			i++;
		}
		ft_setindex(&stack);
	}
	// bottom_rotate(&stack);
	return (0);
}