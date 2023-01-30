/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:55 by clballes          #+#    #+#             */
/*   Updated: 2023/01/30 10:46:09 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_push_list	*ft_push_lstnew(int num)
{
	t_push_list	*list;

	list = malloc(sizeof(t_push_list));
	if (!list)
		return (NULL);
	list->value = num;
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

t_push_list	*ft_push_lstlast(t_push_list *lst)
{
	t_push_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_push_lstadd_back(t_push_list **lst, t_push_list *new)
{
	t_push_list	*list;

	if (*lst && new)
	{
		list = ft_push_lstlast(*lst);
		list->next = new;
		new->previous = list;
		new->next = NULL;
	}
	else
		*lst = new;
}

int	ft_push_lstsize(t_push_list	*lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}	
	return (i);
}
