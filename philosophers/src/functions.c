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

void	print(t_all *all, int idx, t_philo *philo)
{
	long long int	time;

	time = get_time() - all->time_start;
	if (idx == 0) //sleeping
		printf("[%lld] num philo:%d is sleeping\n", time, philo->num);
}

void	to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->l_fork].fork);
	printf("left fork taken num philo:%d\n", philo->num);
	pthread_mutex_lock(&philo[philo->r_fork].fork);
	// printf("right fork taken num philo:%d\n", philo[0].num);
	printf("philo eating num philo:%d\n", philo[0].num);
	// usleep();
	pthread_mutex_unlock(&philo[philo->l_fork].fork);
	pthread_mutex_unlock(&philo[philo->r_fork].fork);
}

void	to_sleep(t_all *all, t_philo *philo)
{
	print(all, 0, philo);
	usleep_time(all->time_to_sleep);
}

void	to_think(t_all *all)
{
	printf("[%ld] %d is thinking\n", all->get_time, all->philo[0].num);
}