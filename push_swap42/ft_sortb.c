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
	int	size_a;
	t_push_list *temp;

	temp = *stack;
	size_a = 0;
	if (temp)
	{
		temp = *stack;
		size_a = findmax(stack);
		if (temp->next->index == (max - 1))
		{
			printf("holaaa\n");
			swap(stack, 'a');
			temp = *stack;
		}
		while(temp)
		{
			if (temp->index == size_a)
			{
				if(temp->next == NULL)
					break;
				else
					bottom_rotate(stack, 'a');
			}
			temp = temp->next;
		}
	}
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
		send(stack_b, stack, 'a');
	else if (cont >= (size / 2))
	{
		printf("entres aqui bitx??????\n");
		cont = size - cont;
		while (cont--)
		{
			temp_b = *stack_b;
			if (temp_b->index == (max - 1))
				send(stack_b, stack, 'a');
			if (temp_b->index == (max - 2))
			{
				send(stack_b, stack, 'a');
				if (ft_push_lstsize(*stack) >= 1)
					top_rotate(stack, 'a');
			}
			bottom_rotate(stack_b, 'b');
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
			printf("el max es: %d\n", max);
			temp_b = *stack_b;
			if (temp_b->index == (max - 1))
			{
				send(stack_b, stack, 'a');
				cont = cont_stackb(stack_b, max);
				temp_b = *stack_b;
			}
			if (temp_b->index == (max - 2))
			{
				send(stack_b, stack, 'a');
				if (ft_push_lstsize(*stack) >= 1)
					top_rotate(stack, 'a');
				temp_b = *stack_b;
			}
			top_rotate(stack_b, 'b');
		}
		send(stack_b, stack, 'a');
		temp = *stack;
		if (ft_push_lstsize(*stack) >= 2)
			ft_reduce_moves(stack, max);
	}
	return (0);
}



void	sort_b(t_push_list **stack, t_push_list **stack_b,
			t_push_list	*temp_b, t_push_list *temp)
{
	int	max;
	int	size;
	int cont;

	cont = 0;
	size = ft_push_lstsize(*stack_b);
	temp_b = *stack_b;
	while (temp_b && max > 2)
	{
			// print_list(stack, stack_b);
			max = findmax(stack_b);
			if (max >= 0 && max <= 2)
				break;
			cont = cont_stackb(stack_b, max);
			rotate_b(stack, stack_b, cont, max);
			print_list(stack, stack_b);
			temp_b = *stack_b;
			temp = *stack;
			//print_list(stack, stack_b);
	}
	size = ft_push_lstsize(*stack_b);
	if (size <= 2)
		sort_two(stack, stack_b, size);
	print_list(stack, stack_b);
}


void	sort_two(t_push_list **stack, t_push_list **stack_b, int size)
{
	t_push_list *temp;

	temp = *stack;
	if (size == 2)
	{
		if (temp->index < temp->next->index)
			swap (stack, 'a');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
	}
	else if (size == 1)
	{
		send(stack_b, stack, 'a');
		temp = *stack;
		if (temp->index > temp->next->index)
			swap (stack, 'a');
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
