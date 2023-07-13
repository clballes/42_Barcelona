/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:58:56 by clballes          #+#    #+#             */
/*   Updated: 2023/07/10 12:58:57 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 == 0)
		usleep_time(philo->all->time_to_eat);
	if (philo->all->n_philo != 1)
	{
		if (is_dead(philo) != 1)
		{
			while (philo->all->dead == 0) //comprobamos q no esten muertos
			{
				if (to_think(philo) != 0 || to_eat(philo) != 0  || to_sleep(philo) != 0)
				{
					break ;
				}
			}
		}
	}
	return (NULL);
}

void	start_philo(t_all *all)
{
	pthread_t		*id;
	int				i;

	i = 0;
	id = malloc(sizeof(pthread_t) * all->n_philo);
	if (!id)
		return ;
	pthread_mutex_init(&all->print, NULL);
	while (i < all->n_philo)
	{
		if (pthread_create(&id[i], NULL, thread_routine, &all->philo[i]) != 0)
		{
			free(id);
			return ;
		}
		// printf("thread started: %d\n", i + 1);
		i++;
	}
	i = 0;
	while (all->n_philo > i)
	{
		if (pthread_join(id[i], NULL) != 0)
			return ;
		// printf("thread finished: %d\n", i + 1);
		i++;
	}
	pthread_mutex_destroy(&all->print);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (argc == 5 || argc == 6)
	{
		all->philo = malloc(sizeof(t_philo) * all->n_philo);
		if (all->philo == NULL)
		{
			free(all->philo); //Clean up allocated memory before returning
			return (0);
		}
		init(argv, all);
		init_philo(all);
		start_philo(all);
	}
	else
		write(2, "Missing arguments\n", 19);
	free(all);
	free(all->philo); //free elemnts
	return (0);
}
