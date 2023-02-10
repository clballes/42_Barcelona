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
	t_push_list	*temp_b;
	t_push_list	*temp;
	int			half;
	int			beg;
	int			end;
	int			len_num;
	int			size_b;

	beg = 0;
	end = 19;
	len_num = 0;
	size_b = 0;
	half = len / 2;
	temp = *stack;
	temp_b = *stack_b;
	if (temp_b == NULL)
	{
		sort_hundred(stack, stack_b, half, beg, end, len_num);
		temp_b = *stack_b;
		temp = *stack;
	}
	while (temp_b && temp != NULL)
	{
		size_b = ft_push_lstsize(temp_b);
		if ((size_b + 1) >= len_num)
		{
			sort_hundred(stack, stack_b, half, (beg + len_num), (end + len_num), len_num);
			temp_b = *stack_b;
			temp = *stack;
			len_num += 20;
		}
	}
	sort_b(stack, stack_b, temp_b, temp);
}

void	sort_hundred(t_push_list **stack, t_push_list **stack_b, int half, int beg, int end, int len_num)
{
	t_push_list	*temp;
	int			cont;

	cont = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index >= beg && temp->index <= end)
		{
			cont = chunk(stack, stack_b, half, cont, end, len_num);
			temp = *stack;
		}
		else
		{
			temp = temp->next;
			cont++;
		}
	}
}

int	chunk(t_push_list **stack, t_push_list **stack_b, int half, int cont, int end, int len_num)
{
	if (cont < half)
		cont = ft_sort_chunk_ra(stack, stack_b, cont, end, len_num);
	else if (cont >= half)
	{
		cont = (half * 2) - cont;
		cont = ft_sort_chunk_rra(stack, stack_b, cont, end, len_num);
	}
	return (cont);
}

int	ft_sort_chunk_rra(t_push_list **stack, t_push_list **stack_b, int cont, int end, int len_num)
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
	else if (temp_b->index <= ((end + len_num)/ 2))
	{
		if (temp->index == len_num)
			return (0);
		top_rotate(stack_b, 'b');
	}
	else
		return (0);
	return (0);
}

int	ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b, int cont, int end, int len_num)
{
	t_push_list	*temp;
	t_push_list	*temp_b;

	temp = *stack;
	while (cont--)
		top_rotate(stack, 'a');
	send(stack, stack_b, 'b');
	temp_b = *stack_b;
	int res;
	res = (end + len_num) / 2;
	if (temp_b->next == NULL)
		return (0);

	if (temp_b->index <= ((end + len_num)/ 2))
	{
		if (ft_push_lstsize(*stack) == 0 && temp->previous == NULL)
		 	return (0);
		top_rotate(stack_b, 'b');
	}
	else
		return (0);
	return (0);
}