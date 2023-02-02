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
	int			chunk;
	int			size_b;

	beg = 0;
	end = 0;
	chunk = 20;
	half = len / 2;
	temp = *stack_b;
	if (temp == NULL)
		sort_hundred(stack, stack_b, half, beg, (end + 19));
	while (temp)
	{
		size_b = ft_push_lstsize(temp);
		printf("SIZE B ES:	%d\n", size_b);
		if (size_b >= chunk)
		{
			sort_hundred(stack, stack_b, half, (beg + chunk), (end + chunk));
			chunk = chunk + 20;
		}
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
		print_list(stack, stack_b);
	}
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
	else if (temp_b->index <= (end / 2))
		top_rotate(stack_b, 'b');
	else
		return (0);
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
	else if (temp_b->index <= (end / 2))
		top_rotate(stack_b, 'b');
	else
		return (0);
	return (0);
}