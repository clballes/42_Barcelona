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

int	ft_strcpy(char *dst, char *src)
{
	int	i;
	int	resultado;

	i = 0;
	resultado = ft_strlen(src);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		printf("el desti en el copy es: %c\n", dst[i]);
		i++;

	}	
	dst[i] = '\0';
	return (resultado);
}