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
	int	num;
	int	r_fork;
	int	l_fork;
}				t_philo;

typedef struct s_all
{
	t_philo				*philo;
	long int			num_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			get_time;
	long int			death;
	pthread_mutex_t		mutex;
}				t_all;

int		ft_atoi(const char *str);
void	to_sleep(t_all *all);
void	to_think(t_all *all);
void	get_time(t_all *all);
#endif