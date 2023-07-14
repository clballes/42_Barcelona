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
	if (idx == 0 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %sis sleeping%s\n",
			time, CYAN, philo->num, RESET, BLUE, RESET);
	if (idx == 1 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %sis eating%s\n",
			time, CYAN, philo->num, RESET, GREEN, RESET);
	if (idx == 2 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %shas taken left fork%s\n",
			time, CYAN, philo->num, RESET, MAGENTA, RESET);
	if (idx == 3 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %shas taken right fork%s\n",
			time, CYAN, philo->num, RESET, MAGENTA, RESET);
	if (idx == 4 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %sis thinking%s\n",
			time, CYAN, philo->num, RESET, YELLOW, RESET);
	if (idx == 5 && !philo->all->dead)
		printf("[%lld] %sphilo %d%s %sdied%s\n",
			time, CYAN, philo->num, RESET, RED, RESET);
	pthread_mutex_unlock(&philo->all->print);
}

void	is_dead(t_all *all)
{
	long long int	time;
	int				i;

	while (all->dead == 0)
	{
		i = 0;
		while(i < all->n_philo)
		{
			time = get_time() - all->time_start;
			// if (game->philos[i].eaten == game->n_eats)
			// dead = 1;
			pthread_mutex_lock(&all->died);
			if (time - all->philo[i].finish_meal >= all->time_to_die)
			{
				print(5, &all->philo[i]);
				all->dead = 1;

			}
			pthread_mutex_unlock(&all->died);
			++i;
		}
	}
}

int	to_eat(t_philo *philo)
{
	if (philo->all->dead == 1)
		return (1);
	pthread_mutex_lock(philo->l_fork);
	print(2, philo);
	// if (philo->all->n_philo == 1)
	// 	usleep_time()
	pthread_mutex_lock(&philo->r_fork);
	print(3, philo);
	print(1, philo);
	pthread_mutex_lock(&philo->all->died);
	philo->finish_meal = get_time() - philo->all->time_start;
	pthread_mutex_unlock(&philo->all->died);
	philo->times_eat++;
	usleep_time(philo->all->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	return (0);
}

int	to_sleep(t_philo *philo)
{
	if (philo->all->dead == 1)
		return (1);
	print(0, philo);
	usleep_time(philo->all->time_to_sleep);
	return (0);
}

int	to_think(t_philo *philo)
{
	if (philo->all->dead == 1)
		return (1);
	print(4, philo);
	return (0);
}
