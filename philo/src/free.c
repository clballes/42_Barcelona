/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:58:27 by clballes          #+#    #+#             */
/*   Updated: 2023/07/14 12:58:28 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_mutex(t_all *all)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&all->print);
	pthread_mutex_destroy(&all->died);
	while (i < all->n_philo)
	{
		pthread_mutex_destroy(&[i].r_fork);
		pthread_mutex_destroy(all->philo[i].l_fork);
		i++;
	}
}
