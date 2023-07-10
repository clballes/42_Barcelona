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

void	init(char **argv, t_all *all)
{
	all->num_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_sleep = ft_atoi(argv[3]);
	all->time_to_eat = ft_atoi(argv[4]);
	all->death = 0;
}

void	init_philo(t_all *all)
{
	int		i;
	int		philo;
	int		index;

	i = 0;
	index = 0;
	philo = 1;
	while (i < all->num_philo)
	{
		all->philo[index].num = philo;
		all->philo[index].r_fork = 0;
		all->philo[index].l_fork = 0;
		i++;
		philo++;
		index++;
	}
	// printf("el philo en la rimera pos es %d\n", all->philo->num);
}

void	*thread_routine(void *arg)
{
	t_all	*all;

	all = (t_all *)arg;
	if (all->num_philo % 2 == 0)
	{
		printf("soy numero par\n");
		//eat(all); que se esperen
	}
	else if (all->num_philo == 1)
		printf("eating solo\n");
	else
	{
		while (all->death == 0) //comprobamos q no esten muertos
		{
			// printf("klk soy un numero impar\n");
			to_think(all);
			// to_sleep(all);
			break;
		}
	}
	return (NULL);
}

void	start_philo(t_all *all)
{
	pthread_t		*id;
	
	int				i;

	i = 0;
	id = malloc(sizeof(pthread_t) * all->num_philo); // free malloc list
	if (!id)
		return ;
	pthread_mutex_init(&all->mutex, NULL); //iniciamos el mutex
	get_time(all);
	while (i < all->num_philo)
	{
		if (pthread_create(&id[i], NULL, thread_routine, (void *)all) != 0)
		{
			free(id);
			return ; //there was an error
		}
		// printf("thread started: %d\n", i);
		i++;
	}
	i = 0;
	while (all->num_philo > i)
	{
		if (pthread_join(id[i], NULL) != 0)
			return ; //there was an error
		// printf("thread finished: %d\n", i);
		i++;
	}
	pthread_mutex_destroy(&all->mutex);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (argc == 5 || argc == 6)
	{
		all->philo = malloc(sizeof(t_philo) * all->num_philo);
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
