/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:51:17 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 10:40:18 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//
void	sort(t_push_list *stack, t_push_list *stack_b, int len)
{
	if (len == 3)
		sort_three(&stack, 'a');
	if (len == 5 || len == 4)
		sort_five(&stack, &stack_b, len);
	if (len > 5)
		range_sort(&stack, &stack_b, len);
}

int	main(int argc, char **argv)
{
	int			len;
	t_push_list	*stack;
	t_push_list	*stack_b;

	stack = NULL;
	stack_b = NULL;
	len = 1;
	if (argc == 1)
		return (0);
	else
	{
		ft_check(argc, argv);
		while (argv[len])
		{
			take_numbers(&stack, ft_atoi(argv[len]));
			len++;
		}
		ft_setindex(&stack);
		if (ft_sort(&stack) == 0)
			return (0);
	}
	len = len - 1;
	if (ft_checkindex(&stack) == 0)
		sort(stack, stack_b, len);
	return (0);
}
