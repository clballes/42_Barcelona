/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:11:58 by clballes          #+#    #+#             */
/*   Updated: 2023/03/07 17:11:59 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"
#include "libft.h"

t_map	*ft_lstnew_long(void	*content)
{
	t_map	*list;

	list = malloc(sizeof(t_map));
	if (!list)
		return (NULL);
	list->line = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_long(t_map **lst, t_map *new)
{
	t_map	*last;

	if (*lst && new)
	{
		last = ft_lstlast_long(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_map	*ft_lstlast_long(t_map *lst)
{
	t_map	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	write_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	ft_strncmp_long(char c, char *s2)
{
	int	i;

	i = 0;
	while (c != '\0' && s2[i] != '\0')
	{
		while (c != s2[i] && s2[i] != '\0')
			i++;
		if (c == s2[i])
			return (0);
		else
			return (1);
	}
	return (1);
}
