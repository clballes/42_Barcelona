/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:49:04 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:14:07 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort(t_push_list **stack, t_push_list **stack_b, int len)
{
	if (len <= 100)
		range_chunk(stack, stack_b, 0, 0);
	else
		range_chunk500(stack, stack_b, 0, 0);
}

void	range_chunk500(t_push_list **stack, t_push_list **stack_b,
		int end, int size_b)
{
	t_push_list	*temp_b;
	t_push_list	*temp;
	int			i;

	i = 61;
	temp = *stack;
	temp_b = *stack_b;
	if (temp_b == NULL)
	{
		sort_5hundred(stack, stack_b, (end + i));
		temp_b = *stack_b;
		temp = *stack;
	}
	while (temp_b && temp != NULL)
	{
		size_b = ft_push_lstsize(temp_b);
		if ((size_b + 1) >= i)
		{
			i += 61;
			sort_5hundred(stack, stack_b, (end + i));
			temp_b = *stack_b;
			temp = *stack;
		}
	}
	sort_b(stack, stack_b, temp_b, temp);
}

void	sort_5hundred(t_push_list **stack, t_push_list **stack_b, int end)
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
			cont = chunk500(stack, stack_b, cont, end);
			temp = *stack;
		}
		else
		{
			temp = temp->next;
			cont++;
		}
	}
}

int	chunk500(t_push_list **stack, t_push_list **stack_b, int cont, int end)
{
	int	size_a;

	size_a = ft_push_lstsize(*stack);
	if (end > 60)
		end += end - 61;
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

void	cont_rotate(t_push_list **stack, t_push_list **stack_b,
		int cont, int max)
{
	while (cont--)
	{
		rotate_op2(stack, stack_b, max);
		cont = cont_stackb(stack_b, max);
	}
	rotate_op_send(stack, stack_b, max);
}
