/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:52:16 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 13:59:49 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_push_list **stack, t_push_list **stack_b, int half)
{
	t_push_list	*temp;
	int			cont;

	cont = 0;
	half = half / 2;
	temp = *stack;
	while (temp)
	{
		if (temp->index <= 8)
		{
			cont = chunk(stack, stack_b, half, cont);
			temp = *stack;
		}
		else
		{
			temp = temp->next;
			cont++;
		}
	}
	print_list(stack, stack_b);
}

int	chunk(t_push_list **stack, t_push_list **stack_b, int half, int cont)
{
	if (cont < half)
		cont = ft_sort_chunk_ra(stack, stack_b, cont);
	else if (cont >= half)
	{
		cont = (half * 2) - cont;
		cont = ft_sort_chunk_rra(stack, stack_b, cont);
	}
	return (cont);
}

int	ft_sort_chunk_rra(t_push_list **stack, t_push_list **stack_b, int cont)
{
	t_push_list	*temp;
	t_push_list	*temp_b;

	temp = *stack;
	while (cont--)
		bottom_rotate(stack, 'a');
	send(stack, stack_b, 'b');
	temp_b = *stack_b;
	if (temp_b->next == NULL)
		return (0);
	else
	{
		if (temp->index < 4)
			top_rotate(stack_b, 'b');
		else
			return (0);
	}
	return (0);
}

int	ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b, int cont)
{
	t_push_list	*temp;
	t_push_list	*temp_b;

	temp = *stack;
	while (cont--)
		top_rotate(stack, 'a');
	send(stack, stack_b, 'b');
	temp_b = *stack_b;
	if (temp_b->next == NULL)
		return (0);
	else
	{
		if (temp->index < 4)
			top_rotate(stack_b, 'b');
		else
			return (0);
	}
	return (0);
}
