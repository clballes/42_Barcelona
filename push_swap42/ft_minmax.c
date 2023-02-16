/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:15:48 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 10:22:09 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_contmin(t_push_list **stack)
{
	t_push_list	*temp;
	t_push_list	*temp2;
	int			cont;

	temp = *stack;
	temp2 = *stack;
	cont = 1;
	while (temp2)
	{
		if (temp2->index < temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	temp2 = *stack;
	while (temp2)
	{
		if (temp->index == temp2->index)
		{
			return (cont);
		}
		cont++;
		temp2 = temp2->next;
	}
	return (cont);
}
