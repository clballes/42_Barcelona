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
	printf(" num philo num forks %d\n", all->num_philo);
	printf(" time to die %d\n", all->time_to_die);
	printf(" time to sleep %d\n", all->time_to_sleep);
	printf(" time to eat %d\n", all->time_to_eat);
}

void	eat()
{
	
}

void	*thread_routine(void *data)
{
	(void)data;
	// eat();
	printf("estoy en la rutine\n");
	return (NULL); //The thread ends here.
}

void	start_philo(t_all *all)
{
	pthread_t		*id;
	struct timeval	current_time;
	int				i;

	i = 0;
	id = malloc(sizeof (all->num_philo) + 1); // free malloc list
	if (!id)
		return ;
	
	gettimeofday(&current_time, NULL);

	while (all->num_philo > i)
	{
		if (pthread_create(&id[i], NULL, thread_routine, &all->philo[i]) != 0)
			return ; //there was an error
		i++;
	}
	printf("Current time: %ld seconds, %d microseconds\n",
		current_time.tv_sec, current_time.tv_usec);
}

int	main(int argc, char **argv)
{
	t_philo	*list_philo;
	t_all	*all;

	list_philo = malloc(sizeof(t_philo)); //shaurà de fer free al sortir
	all = malloc(sizeof(t_all)); //shaurà de fer free al sortir
	if (!list_philo)
		return (0);
	if (!all)
		return (0);
	if (argc == 5 || argc == 6)
	{
		init(argv, all);
		start_philo(all);
	}
	else
		write(2, "Missing arguments\n", 19);
	return (0);
}
