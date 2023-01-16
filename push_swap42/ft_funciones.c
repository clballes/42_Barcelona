/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funciones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:04:56 by clballes          #+#    #+#             */
/*   Updated: 2022/11/04 18:20:03 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_numbers(t_push_list **stack, int num)
{
	t_push_list *tmp;

	tmp = ft_push_lstnew(num);
	ft_push_lstadd_back(stack, tmp);
}

void    ft_setindex(t_push_list **stack)
{
	int i;
	int size_list;
	t_push_list *tmp;
	t_push_list *tmp2;

	i = 0;
	tmp = *stack;
	tmp2 = *stack;
	size_list = ft_push_lstsize(tmp);
	while (tmp)
	{
		if(tmp->value < tmp2->value)
			i++;	
		if(tmp2->next == NULL)
		{
			tmp->index = (size_list - i);
			tmp = tmp->next;
			tmp2 = *stack;
			i = 0;
		}
		else
			tmp2 = tmp2->next;
	}
}

void	ft_setletter(t_push_list **stack, t_push_list **stack_b)
{
	t_push_list *temp;
	t_push_list *temp2;

	temp = *stack;
	temp2 = *stack_b;
	if (temp)
		temp->id = 'a';
	else
		temp->id = 'b';
}