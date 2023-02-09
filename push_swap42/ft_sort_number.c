/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:54 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 10:38:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push_list **stack, char c, int index2, int index)
{
	int			index3;
	t_push_list	*temp;

	temp = *stack;
	index3 = temp->next->next->index;
	if ((index3 > index2) && (index3 > index) && (index > index2))
		swap(stack, c);
	else if ((index3 < index2) && index2 < index && (index > index3))
	{
		swap(stack, c);
		bottom_rotate(stack, c);
	}
	else if ((index > index2) && (index > index3) && index2 < index3)
		top_rotate(stack, c);
	else if ((index2 > index) && (index2 > index3))
	{
		if (index < index3)
		{
			swap(stack, c);
			top_rotate(stack, c);
		}
		else
			bottom_rotate(stack, c);
	}
}

void	sort_five(t_push_list **stack, t_push_list **stack_b, int len)
{
	int	resultado;
	int	j;

	j = 1;
	if (len == 5)
	{
		resultado = findmin(stack);
		send_minimum(stack, stack_b, resultado);
	}
	if (len == 5 || len == 4)
	{
		resultado = findmin(stack);
		if (resultado == 3 || resultado == 4)
			resultado = resultado + 1;
		if (resultado >= 0 && resultado <= 5)
			send_minimum(stack, stack_b, resultado);
	}
	ft_longword_index(stack);
	send(stack_b, stack, 'a');
	if (len == 5)
		send(stack_b, stack, 'a');
}

void	ft_longword_index(t_push_list **stack)
{
	t_push_list	*temp;
	int			index2;
	int			index;

	temp = *stack;
	index = temp->index;
	index2 = temp->next->index;
	sort_three(stack, 'a', index2, index);
}
