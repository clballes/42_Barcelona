/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:53:47 by clballes          #+#    #+#             */
/*   Updated: 2023/02/10 13:53:49 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cont_stackb(t_push_list **stack_b, int max)
{
	t_push_list	*temp_b;
	int			cont;

	cont = 0;
	temp_b = *stack_b;
	while (temp_b)
	{
		if (temp_b->index == max)
			return (cont);
		cont++;
		temp_b = temp_b->next;
	}
	return (0);
}

void	ft_reduce_moves(t_push_list **stack, int max)
{
	t_push_list *temp;

	temp = *stack;
	if (!temp->next)
		return ;
	if(temp->index > temp->next->index)
	{
		swap(stack, 'a');
		temp = *stack;
	}
	while(temp->next)
		temp = temp->next;
	if (temp->index < max)
		bottom_rotate(stack, 'a');
}

int	rotate_b(t_push_list **stack, t_push_list **stack_b, int cont, int max)
{
	int	size;
	t_push_list *temp_b;
	t_push_list *temp;

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
			temp_b = *stack_b;
			if (temp_b->index == (max - 1))
				send(stack_b, stack, 'a');
			else if(temp_b->index == (max - 2))
			{
				send(stack_b, stack, 'a');
				if (ft_push_lstsize(*stack) > 1)
				{
					top_rotate(stack, 'a');
				}
			}
			else
				bottom_rotate(stack_b, 'b');
			cont = cont_stackb(stack_b, max);
		}
		send(stack_b, stack, 'a');
		temp = *stack;
		if (ft_push_lstsize(*stack) >= 2)
			ft_reduce_moves(stack, max);
	}
	else if (cont < (size / 2))
	{
		while (cont--)
		{
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
			cont = cont_stackb(stack_b, max);
		}
		temp = *stack;
		send(stack_b, stack, 'a');
		if (ft_push_lstsize(*stack) >= 2)
			ft_reduce_moves(stack, max);
	}
	return (0);
}



void	sort_b(t_push_list **stack, t_push_list **stack_b,
			t_push_list	*temp_b, t_push_list *temp)
{
	int	max;
	int cont;

	cont = 0;
	max = 0;
	max = findmax(stack_b);
	temp_b = *stack_b;
	while (temp_b && max >= 1)
	{
		max = findmax(stack_b);
		cont = cont_stackb(stack_b, max);
		rotate_b(stack, stack_b, cont, max);
		temp_b = *stack_b;
		temp = *stack;
	}
}

void	ft_checka(t_push_list **stack)
{
	t_push_list *temp;

	temp = *stack;
	while (temp->index < 4)
	{
		if (temp->index > temp->next->index)
			swap(stack, 'a');
		temp = temp->next;
	}
}

int	findmax(t_push_list **stack_b)
{
	t_push_list	*temp;
	t_push_list	*temp2;

	temp = *stack_b;
	temp2 = *stack_b;
	while (temp2)
	{
		if (temp2->index > temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp->index);
}
