/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funciones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:04:56 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:17:14 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	take_numbers(t_push_list **stack, int num)
{
	t_push_list	*tmp;

	tmp = ft_push_lstnew(num);
	ft_push_lstadd_back(stack, tmp);
}

void	ft_setindex(t_push_list **stack)
{
	int			i;
	int			size_list;
	t_push_list	*tmp;
	t_push_list	*tmp2;

	i = 0;
	tmp = *stack;
	tmp2 = *stack;
	size_list = ft_push_lstsize(tmp);
	while (tmp)
	{
		if (tmp->value < tmp2->value)
			i++;
		if (tmp2->next == NULL)
		{
			tmp->index = (size_list - i -1);
			tmp = tmp->next;
			tmp2 = *stack;
			i = 0;
		}
		else
			tmp2 = tmp2->next;
	}
}

void	send_minimum(t_push_list **stack, t_push_list **stack_b, int resultado)
{
	if (resultado == 2)
		swap(stack, 'a');
	else if (resultado >= 3 && resultado <= 5)
	{
		bottom_rotate(stack, 'a');
		if (resultado == 3 || resultado == 4)
			bottom_rotate(stack, 'a');
		if (resultado == 3)
			bottom_rotate(stack, 'a');
	}
	send(stack, stack_b, 'b');
}

int	ft_checkindex(t_push_list **stack)
{
	t_push_list	*temp;
	int			i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		if (temp->index == 0)
		{
			i++;
			temp = temp->next;
			while (temp->index == i)
			{
				i++;
				temp = temp->next;
				if (temp->next == NULL)
					exit (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

int	ft_sort(t_push_list **stack)
{
	t_push_list	*temp;

	temp = *stack;
	if (temp->next == NULL)
		return (0);
	if (temp->next->next == NULL)
	{
		if (temp->index < temp->next->index)
			return (0);
		else
		{
			swap(stack, 'a');
			return (0);
		}
	}
	return (1);
}
