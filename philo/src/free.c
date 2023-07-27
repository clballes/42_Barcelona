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
		pthread_mutex_destroy(&all->philo[i].r_fork);
		pthread_mutex_destroy(all->philo[i].l_fork);
		i++;
	}
}

void	philo_join_free(t_all *all, pthread_t *id)
{
	int	i;

	i = 0;
	while (all->n_philo > i)
	{
		if (pthread_join(id[i], NULL) != 0)
			return ;
		i++;
	}
	free(id);
	free_mutex(all);
	free(all->philo);
	free(all);
}

void	print(int idx, t_philo *philo)
{
	long long int	time;
	const char		*colors[7] = {SLEEPING, EATING, \
			L_FORK, R_FORK, THINKING, DIED, ATE};

	time = get_time() - philo->all->time_start;
	pthread_mutex_lock(&philo->all->print);
	if (!philo->all->dead)
		printf(colors[idx], time, RESET, philo->num, RESET);
	pthread_mutex_unlock(&philo->all->print);
}

int	ft_strlen(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
