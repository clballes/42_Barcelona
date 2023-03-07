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

t_map	*ft_lstnew(void	*content)
{
	t_map	*list;

	list = malloc(sizeof(t_map));
	if (!list)
		return (NULL);
	list->line = line;
	list->next = NULL;
	return (list);
}
