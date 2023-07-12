#include "philosophers.h"

void	init_philo(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->num_philo)
	{
		all->philo[i].num = i + 1;
		all->philo[i].l_fork = i;
		all->philo[i].r_fork = i + 1;
		if (pthread_mutex_init(&all->philo[i].fork, NULL) != 0)
			return ;
		i++;
	}
}

void	init(char **argv, t_all *all)
{
	all->num_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_sleep = ft_atoi(argv[3]);
	all->time_to_eat = ft_atoi(argv[4]);
	all->time_start = get_time();
	all->death = 0;
}
