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

t_line	*ft_lstnew_long(void	*content)
{
	t_line	*list;

	list = malloc(sizeof(t_line));
	if (!list)
		return (NULL);
	list->line = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_long(t_line **lst, t_line *new)
{
	t_line	*last;

	if (*lst && new)
	{
		last = ft_lstlast_long(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_line	*ft_lstlast_long(t_line *lst)
{
	t_line	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	write_error(char error)
{
	write (2, "Error ", 6);
	if (error == '0')
		write (2, "Not ber extension\n", 18);
	else if (error == '1')
		write (2, "Map not loaded\n", 15);
	else if (error == '2')
		write (2, "Map not rectangular\n", 20);
	else if (error == '3')
		write (2, "Map not minimum elements\n", 25);
	else if (error == '4')
		write (2, "Map not sourrounded by walls\n", 29);
	else if (error == '0')
		write (2, "Not enough arguments\n", 21);
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