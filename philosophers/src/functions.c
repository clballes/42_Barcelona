/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:41:07 by clballes          #+#    #+#             */
/*   Updated: 2023/07/10 17:41:08 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_all *all)
{
	pthread_mutex_lock(&all->mutex);
	// all->philo->l_fork = 1;
	// all->philo->r_fork = 1;
	printf("he puesto los forks a 1 \n");
	pthread_mutex_unlock(&all->mutex);
}

void	to_sleep(t_all *all)
{
	// t_philo	*philo;

	// philo = *all->philo;
	printf("%d %ld is sleeping\n", all->philo[0].num, all->get_time);
}

void	to_think(t_all *all)
{
	// t_philo	*philo;

	// philo = *all->philo;
	// printf("%d %ld is thinking\n", all->philo->num, all->get_time);
	printf("[%ld] %d is thinking\n", all->get_time, all->philo[0].num);
}