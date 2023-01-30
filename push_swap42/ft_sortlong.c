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

void	range_chunk(t_push_list **stack, t_push_list **stack_b, int len)
{
	t_push_list	*temp;
	int			half;
	int			beg;
	int			end;

	beg = 0;
	end = 0;
	half = len / 2;
	temp = *stack_b;
	if (temp == NULL)
	{
		beg = 0;
		end = 19;
		sort_hundred(stack, stack_b, half, beg, end);
	}
	while (len > 20)
	{
		beg = 20;
		end = 39;
		sort_hundred(stack, stack_b, half, beg, end);
		beg = 40;
		end = 59;
		sort_hundred(stack, stack_b, half, beg, end);
	}

}

void	sort_hundred(t_push_list **stack, t_push_list **stack_b, int half, int beg, int end)
{
	t_push_list	*temp;
	int			cont;

	cont = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index >= beg && temp->index <= end)
		{
			cont = chunk(stack, stack_b, half, cont, end);
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

int	chunk(t_push_list **stack, t_push_list **stack_b, int half, int cont, int end)
{
	if (cont < half)
		cont = ft_sort_chunk_ra(stack, stack_b, cont, end);
	else if (cont >= half)
	{
		cont = (half * 2) - cont;
		cont = ft_sort_chunk_rra(stack, stack_b, cont, end);
	}
	return (cont);
}

int	ft_sort_chunk_rra(t_push_list **stack, t_push_list **stack_b, int cont, int end)
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
		if (temp->index >= (end / 2))
			top_rotate(stack_b, 'b');
		else
			return (0);
	}
	return (0);
}

int	ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b, int cont, int end)
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
		if (temp->index >= (end / 2))
			top_rotate(stack_b, 'b');
		else
			return (0);
	}
	return (0);
}
