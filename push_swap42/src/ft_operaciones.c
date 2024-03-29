/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operaciones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:22 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:17:30 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "ft_printf.h"

void	swap(t_push_list **stack, char c)
{
	t_push_list	*first;
	t_push_list	*second;

	first = *stack;
	second = first->next;
	if (first->next == 0)
		return ;
	first->next = second->next;
	first->previous = second;
	if (second->next != 0)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	*stack = second;
	ft_printf("s%c\n", c);
}

void	top_rotate(t_push_list **stack, char c)
{
	t_push_list	*bottom;
	t_push_list	*top;
	t_push_list	*second;

	top = *stack;
	bottom = ft_push_lstlast(top);
	second = top->next;
	second->previous = NULL;
	*stack = second;
	top->next = NULL;
	top->previous = bottom;
	bottom->next = top;
	ft_printf("r%c\n", c);
}

void	bottom_rotate(t_push_list **stack, char c)
{
	t_push_list	*bottom;
	t_push_list	*top;

	top = *stack;
	bottom = ft_push_lstlast(*stack);
	bottom->previous->next = NULL;
	bottom->previous = NULL;
	*stack = bottom;
	bottom->next = top;
	top->previous = bottom;
	ft_printf("rr%c\n", c);
}

void	send(t_push_list **stack_a, t_push_list **stack_b, char c)
{
	t_push_list	*top_a;
	t_push_list	*top_b;

	top_a = *stack_a;
	top_b = *stack_b;
	if (stack_a)
	{
		if (top_a->next)
			top_a->next->previous = NULL;
		*stack_a = top_a->next;
		*stack_b = top_a;
		if (top_b == NULL)
			top_a->next = NULL;
		else
		{
			top_b->previous = top_a;
			top_a->next = top_b;
		}
	}
	ft_printf("p%c\n", c);
}
