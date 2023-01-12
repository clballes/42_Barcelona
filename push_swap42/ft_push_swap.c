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

void	sort(t_push_list **stack, t_push_list **stack_b, int i){
	if (i == 3)
		sort_three(&stack);
	if (i == 5)
		sort_five(&stack, &stack_b);
}

int	main(int argc, char **argv)
{
	int				 	i;
	t_push_list *stack;
	t_push_list *stack_b;

	stack = NULL;
	stack_b = NULL;
<<<<<<< HEAD
=======
	i = 1;
>>>>>>> 9540066a3ae818e87a3d4c965baa755a65201f01
	if (argc == 1)
		write_error();
	else
	{
		ft_check(argc, argv);
	  	while(argv[i])
		{
			take_numbers(&stack, ft_atoi(argv[i]));
			i++;
		}
		ft_setindex(&stack);
	}
<<<<<<< HEAD
	// bottom_rotate(&stack);
=======
	sort(&stack, &stack_b, i);
>>>>>>> 9540066a3ae818e87a3d4c965baa755a65201f01
	return (0);
}