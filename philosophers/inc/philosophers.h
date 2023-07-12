/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:59:11 by clballes          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:15 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct s_all
{
	t_philo				*philo;
	long int			num_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			get_time;
	long long int		time_start;
	long int			death;
	pthread_mutex_t		mutex;
}				t_all;

void			init(char **argv, t_all *all);
void			init_philo(t_all *all);
int				ft_atoi(const char *str);
void			to_sleep(t_all *all, t_philo *philo);
void			to_think(t_all *all);
void			usleep_time(int time);
long long int	get_time(void);
void			to_eat(t_philo *philo);

#endif