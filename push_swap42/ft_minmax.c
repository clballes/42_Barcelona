/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:15:48 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:56:34 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_contmin(t_push_list **stack)
{
	t_push_list	*temp;
	t_push_list	*temp2;
	int			cont;

	temp = *stack;
	temp2 = *stack;
	cont = 1;
	while (temp2)
	{
		if (temp2->index < temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	temp2 = *stack;
	while (temp2)
	{
		if (temp->index == temp2->index)
		{
			return (cont);
		}
		cont++;
		temp2 = temp2->next;
	}
	return (cont);
}

void	rotate_op(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list	*temp_b;

	temp_b = *stack_b;
	if (temp_b->index == (max - 1))
		send(stack_b, stack, 'a');
	else if (temp_b->index == (max - 2))
	{
		send(stack_b, stack, 'a');
		if (ft_push_lstsize(*stack) > 1)
			top_rotate(stack, 'a');
	}
	else
		bottom_rotate(stack_b, 'b');
}

void	rotate_op2(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list	*temp_b;

	temp_b = *stack_b;
	if (temp_b->index == (max - 1))
		send(stack_b, stack, 'a');
	else if (temp_b->index == (max - 2))
	{
		send(stack_b, stack, 'a');
		if (ft_push_lstsize(*stack) > 1)
			top_rotate(stack, 'a');
	}
	else
		top_rotate(stack_b, 'b');
}

int	rotate_b(t_push_list **stack, t_push_list **stack_b, int cont, int max)
{
	int			size;
	t_push_list	*temp_b;
	t_push_list	*temp;

	temp_b = *stack_b;
	temp = *stack;
	size = ft_push_lstsize(*stack_b);
	if (cont == 0)
	{
		send(stack_b, stack, 'a');
		ft_reduce_moves(stack, max);
	}
	else if (cont >= (size / 2))
	{
		cont = size - cont;
		while (cont--)
		{
			rotate_op(stack, stack_b, max);
			cont = cont_stackb(stack_b, max);
		}
		rotate_op_send(stack, stack_b, max);
	}
	else if (cont < (size / 2))
		cont_rotate(stack, stack_b, cont, max);
	return (0);
}

void	rotate_op_send(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list	*temp;

	temp = *stack;
	send(stack_b, stack, 'a');
	if (ft_push_lstsize(*stack) >= 2)
		ft_reduce_moves(stack, max);
}
