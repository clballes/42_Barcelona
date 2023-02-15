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
		cont = size - cont;
		while (cont--)
		{
			bottom_rotate(stack_b, 'b');
			temp_b = *stack_b;
			// print_list(stack, stack_b);
			// printf("EL TEMP INDEX ES %d\n", temp_b->index);
			// printf("EL MAX ES %d\n", max);
			if (temp_b->index == (max - 1))
				send(stack_b, stack, 'a');
		}
		send(stack_b, stack, 'a');
		if (temp)
		{
			temp = *stack;
			if (temp->next->index == (max - 1))
				swap(stack, 'a');
			// print_list(stack, stack_b);
		}
	}
	else if (cont < (size / 2))
	{
		while (cont--)
			top_rotate(stack_b, 'b');
		send(stack_b, stack, 'a');
	}
	return (0);
}



void	sort_b(t_push_list **stack, t_push_list **stack_b,
			t_push_list	*temp_b, t_push_list *temp)
{
	int	max;
	int	size;
	int	cont_size;
	int	i;
	int cont;

	cont = 0;
	cont_size = 0;
	size = ft_push_lstsize(*stack_b);
	i = findmax(stack_b);
	temp_b = *stack_b;
	while (i-- && temp_b && i > 2)
	{
		// if (check_cont(stack, stack_b, max) == 0)
		// {
			max = findmax(stack_b);
			if (max == 2)
				break;
			cont = cont_stackb(stack_b, max);
			rotate_b(stack, stack_b, cont, max);
			temp_b = *stack_b;
			temp = *stack;
		// }
		i = max;
	}
	max = findmax(stack_b);
	if (max <= 2)
		sort_two(stack, stack_b, max);
	// print_list(stack, stack_b);
	
}


void	sort_two(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list *temp_b;

	temp_b = *stack_b;
	if (max == 2)
	{
		if (temp_b->index < temp_b->next->index)
			swap (stack_b, 'b');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
	}
	if (max == 1)
		send(stack_b, stack, 'a');
}



int	check_cont(t_push_list **stack, t_push_list **stack_b, int max)
{
	int	cont_max_nxt;
	int	cont_max_nxt_nxt;


	cont_max_nxt = cont_stackb(stack_b, max);
	cont_max_nxt_nxt = cont_stackb(stack_b, (max - 1));
	if (cont_max_nxt == 0)
		return (0);
	if (cont_max_nxt == cont_max_nxt_nxt - 1)
	{
		while (cont_max_nxt--)
			top_rotate(stack_b, 'b');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
		return (1);
	}
	// else  if (cont_max_nxt_nxt2 < cont_max_nxt)
	// {
	// 	ft_move_ra(stack, stack_b, cont_max_nxt_nxt2);
	// 	return (1);
	// }
	else if (cont_max_nxt == cont_max_nxt_nxt + 1)
	{
		while (cont_max_nxt_nxt--)
			top_rotate(stack_b, 'a');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
		swap(stack, 'a');
		return (1);
	}
	return (0);
}

// void		ft_move_ra(t_push_list **stack, t_push_list **stack_b, int cont_max_nxt_nxt2)
// {
// 	int max;
// 	int cont;
// 	cont = 0;
// 	max = 0;
// 	rotate_b(stack, stack_b, cont_max_nxt_nxt2); //38
// 	if (ft_push_lstsize(*stack) >= 1)
// 		top_rotate(stack, 'a');
// 	max = findmax(stack_b); //40
// 	cont = cont_stackb(stack, stack_b, max);
// 	rotate_b(stack, stack_b, cont);
// 	bottom_rotate(stack, 'a'); // 38 40
// 	max = findmax(stack_b); // 39
// 	cont = cont_stackb(stack, stack_b, max);
// 	rotate_b(stack, stack_b, cont);
// 	swap(stack, 'a');
// }

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
