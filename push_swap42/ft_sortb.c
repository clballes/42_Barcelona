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

int	cont_stackb(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list	*temp_b;
	int			cont;

	cont = 0;
	temp_b = *stack_b;
	if (max == 2)
	{
		if (temp_b->index < temp_b->next->index)
			print_swap(stack_b, 'b');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
	}
	while (temp_b)
	{
		if (temp_b->index == max)
		{
			printf("EL cont ES: %d\n", cont);
			return (cont);
		}
		cont++;
		temp_b = temp_b->next;
	}
	return (0);
}

int	rotate_b(t_push_list **stack, t_push_list **stack_b, int max, int cont)
{
	int	size;

	size = ft_push_lstsize(*stack_b);
	if (cont == 0)
		send(stack_b, stack, 'a');
	else if (cont >= (size / 2))
	{
		cont = (max - cont);
		while (cont--)
			print_rev_rotate(stack_b, 'b');
		send(stack_b, stack, 'a');
		// print_list(stack, stack_b);
	}
	else if (cont < (size / 2))
	{
		while (cont--)
			print_rotate(stack_b, 'b');
		send(stack_b, stack, 'a');
	}
	return (0);
}

void	sort_b(t_push_list **stack, t_push_list **stack_b,
			t_push_list	*temp_b, t_push_list *temp)
{
	int	max;
	int	size;
	int	i;

	size = ft_push_lstsize(*stack_b);
	i = findmax(stack_b);
	temp_b = *stack_b;
	max = findmax(stack_b);
	printf("EL MAXIM ES: %d\n", max);

			check_cont(stack, stack_b, max);
	// while (i-- && temp_b && i > 2)
	// {
			temp_b = *stack_b;
			temp = *stack;
	// 		i = max;
	// }
	max -= 1;
	if (max == 2)
		cont_stackb(stack, stack_b, max);
}

// int	check_cont(t_push_list **stack, t_push_list **stack_b, int max)
// {
// 	int	cont_max_nxt;
// 	int	cont_max_nxt_nxt;
// 	cont_max_nxt = cont_stackb(stack, stack_b, max);
// 	cont_max_nxt_nxt = cont_stackb(stack, stack_b, (max - 1));

// 	if (cont_max_nxt == 0)
// 		return (0);
// 	if (cont_max_nxt == cont_max_nxt_nxt - 1)
// 	{
// 		while (cont_max_nxt--)
// 			print_rotate(stack_b, 'b');
// 		send(stack_b, stack, 'a');
// 		send(stack_b, stack, 'a');
// 		return (1);
// 	}
// 	else if (cont_max_nxt == cont_max_nxt_nxt + 1)
// 	{
// 		while (cont_max_nxt_nxt--)
// 			print_rotate(stack_b, 'a');
// 		send(stack_b, stack, 'a');
// 		send(stack_b, stack, 'a');
// 		print_swap(stack, 'a');
// 		return (1);
// 	}
// 	return (0);
// }

int	check_cont(t_push_list **stack, t_push_list **stack_b, int max)
{
	int cont_max;
	int cont_max2;
	int cont_max3;

	cont_max = cont_stackb(stack, stack_b, max);
	cont_max2 = cont_stackb(stack, stack_b, (max - 1));
	cont_max3 = cont_stackb(stack, stack_b, (max - 2));
	
	printf("el maxim es: %d\n", cont_max);
	printf("el max - 1 es: %d\n", cont_max2);
	printf("el max - 2 es: %d\n", cont_max3);
	if (cont_max3 < cont_max && cont_max < cont_max2)
	{
		rotate_b(stack, stack_b, max, cont_max3);
		if (ft_push_lstsize(*stack) > 1)
			print_rev_rotate(stack, 'a'); //ra per baixar el numero
		cont_max = cont_stackb(stack, stack_b, max);
		rotate_b(stack, stack_b, max, cont_max); //numero gran enviat
		cont_max2 = cont_stackb(stack, stack_b, max);
		rotate_b(stack, stack_b, max, cont_max2);
		print_rev_rotate(stack, 'a');
		print_list(stack, stack_b);
		return (1);
	}
	if (cont_max3 < cont_max && cont_max > cont_max2)
	{
		rotate_b(stack, stack_b, max, cont_max3);
		if (ft_push_lstsize(*stack) > 1)
			print_rev_rotate(stack, 'a'); 
		print_list(stack, stack_b);
		cont_max2 = cont_stackb(stack, stack_b, max);
		rotate_b(stack, stack_b, max, cont_max2);
		print_list(stack, stack_b);

	}

	if (cont_max < cont_max2 && cont_max < cont_max3)
		rotate_b(stack, stack_b, max, cont_max3);
	return 0;

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
