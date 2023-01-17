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

void	sort(t_push_list *stack, t_push_list *stack_b, int i)
{
	if (i == 3)
		sort_three(stack, 'a');
	if (i == 5){
		sort_five(stack, stack_b);
		// print_list(&stack, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	int				 	i;
	t_push_list *stack;
	t_push_list *stack_b;

	stack = NULL;
	stack_b = NULL;
	i = 1;
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
		ft_setletter(&stack, &stack_b);
	}
	i = i - 1;
	sort(stack, stack_b, i);
	// print_list(&stack, &stack_b);
	return (0);
}