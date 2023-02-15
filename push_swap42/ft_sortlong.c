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

void	range_chunk(t_push_list **stack, t_push_list **stack_b,
			int end, int size_b)
{	
	t_push_list	*temp_b;
	t_push_list	*temp;
	int			i;

	i = 19;
	temp = *stack;
	temp_b = *stack_b;
	if (temp_b == NULL)
	{
		sort_hundred(stack, stack_b, (end + i));
		temp_b = *stack_b;
		temp = *stack;
	}
	while (temp_b && temp != NULL)
	{
		size_b = ft_push_lstsize(temp_b);
		if ((size_b + 1) >= i)
		{
			i += 20;
			sort_hundred(stack, stack_b, (end + i));
			temp_b = *stack_b;
			temp = *stack;
		}
	}
	sort_b(stack, stack_b, temp_b, temp);
}

void	sort_hundred(t_push_list **stack, t_push_list **stack_b, int end)
{
	t_push_list	*temp;
	t_push_list	*temp2;
	int			cont;

	cont = 0;
	temp2 = *stack_b;
	temp = *stack;
	while (temp)
	{
		if (temp->index <= end)
		{
			cont = chunk(stack, stack_b, cont, end);
			temp = *stack;
		}
		else
		{
			temp = temp->next;
			cont++;
		}
	}
}

int	chunk(t_push_list **stack, t_push_list **stack_b, int cont, int end)
{
	int	size_a;

	size_a = ft_push_lstsize(*stack);
	if (end > 19)
		end += end - 20;
	if (cont < (size_a / 2))
		cont = ft_sort_chunk_ra(stack, stack_b, cont, end);
	else if (cont >= (size_a / 2))
	{
		if (cont == 0)
		{
			cont = ft_sort_chunk_rra(stack, stack_b, cont, end);
			return (cont);
		}
		cont = size_a - cont;
		cont = ft_sort_chunk_rra(stack, stack_b, cont, end);
	}
	return (cont);
}

int	ft_sort_chunk_rra(t_push_list **stack, t_push_list **stack_b,
		int cont, int end)
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
	else if (temp_b->index <= (end / 2))
		top_rotate(stack_b, 'b');
	else
		return (0);
	return (0);
}

int	ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b,
			int cont, int end)
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
	if (temp_b->index <= (end / 2))
		top_rotate(stack_b, 'b');
	else
		return (0);
	return (0);
}
