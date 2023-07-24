/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:49:28 by clballes          #+#    #+#             */
/*   Updated: 2023/07/12 11:49:29 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->n_philo)
	{
		all->philo[i].all = all;
		all->philo[i].finish_meal = 0;
		all->philo[i].times_eat = 0;
		all->philo[i].num = i + 1;
		if (pthread_mutex_init(&all->philo[i].r_fork, NULL) != 0)
			return ;
		if (i != 0)
			all->philo[i].l_fork = &all->philo[i - 1].r_fork;
		i++;
	}
	all->philo[0].l_fork = &all->philo[i - 1].r_fork;
}

void	init(char **argv, t_all *all)
{
	all->n_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	all->time_start = get_time();
	all->dead = 0;
	if (!argv[5])
		all->n_eats = -1;
	else
		all->n_eats = ft_atoi(argv[5]);
	if (pthread_mutex_init(&all->died, NULL) != 0)
		return ;
	all->philo = malloc(sizeof(t_philo) * all->n_philo);
	if (all->philo == NULL)
		free(all);
	init_philo(all);
}
