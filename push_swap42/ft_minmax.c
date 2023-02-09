/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:15:48 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 10:22:09 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sendx2(t_push_list **stack_b, t_push_list **stack)
{
	send (stack_b, stack, 'a');
	send (stack_b, stack, 'a');
}

int	findmin(t_push_list **stack)
{
	t_push_list	*temp;
	t_push_list	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp2)
	{
		if (temp2->index < temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp->index);
}
