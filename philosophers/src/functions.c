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

void	print(int idx, t_philo *philo)
{
	long long int	time;

	time = get_time() - philo->all->time_start;
	pthread_mutex_lock(&philo->all->print);
	if (idx == 0)
		printf("[%lld] num philo:{%d} is sleeping\n", time, philo->num);
	else if (idx == 1)
		printf("[%lld] num philo:{%d} is eating\n", time, philo->num);
	else if (idx == 2)
		printf("[%lld] num philo:{%d} has taken left fork\n", time, philo->num);
	else if (idx == 3)
		printf("[%lld] num philo:{%d} has taken right fork\n", time, philo->num);
	else if (idx == 4)
		printf("[%lld] num philo:{%d} is thinking\n", time, philo->num);
	pthread_mutex_unlock(&philo->all->print);
}

void	to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print(2, philo);
	pthread_mutex_lock(&philo->r_fork);
	print(3, philo);
	philo->times_eat++;
	print(1, philo);
	usleep_time(philo->all->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	to_sleep(t_philo *philo)
{
	print(0, philo);
	usleep_time(philo->all->time_to_sleep);
}

void	to_think(t_philo *philo)
{
	print(4, philo);
}
