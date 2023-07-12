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
	(void)philo;
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
