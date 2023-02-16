/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:54 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:30:47 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push_list **stack)
{
	int			index3;
	t_push_list	*temp;

	temp = *stack;
	index3 = temp->next->next->index;
	if ((index3 > temp->next->index) && (index3 > temp->index)
		&& (temp->index > temp->next->index))
		swap(stack, 'a');
	else if ((index3 < temp->next->index) && temp->next->index < temp->index
		&& (temp->index > index3))
	{
		swap(stack, 'a');
		bottom_rotate(stack, 'a');
	}
	else if ((temp->index > temp->next->index)
		&& (temp->index > index3) && temp->next->index < index3)
		top_rotate(stack, 'a');
	else if ((temp->next->index > temp->index) && (temp->next->index > index3))
		check_three(stack);
}

void	check_three(t_push_list **stack)
{
	t_push_list	*temp;
	int			index3;

	temp = *stack;
	index3 = temp->next->next->index;
	if (temp->index < index3)
	{
		swap(stack, 'a');
		top_rotate(stack, 'a');
	}
	else
		bottom_rotate(stack, 'a');
}

void	sort_five(t_push_list **stack, t_push_list **stack_b, int len)
{
	int	resultado;
	int	j;

	j = 1;
	if (len == 5)
	{
		resultado = find_contmin(stack);
		send_minimum(stack, stack_b, resultado);
	}
	if (len == 5 || len == 4)
	{
		resultado = find_contmin(stack);
		if (resultado == 3 || resultado == 4)
		{
			resultado = resultado + 1;
			send_minimum(stack, stack_b, resultado);
		}
		else
			send_minimum(stack, stack_b, resultado);
	}
	sort_three(stack);
	send(stack_b, stack, 'a');
	if (len == 5)
		send(stack_b, stack, 'a');
}
