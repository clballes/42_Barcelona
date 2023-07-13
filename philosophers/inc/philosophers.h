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

// defining colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"
#define WHITE     "\033[37m"

typedef struct s_all	t_all;

typedef struct s_philo
{
	int				num;
	int				times_eat;
	long long int	finish_meal;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_all			*all;
}				t_philo;

typedef struct s_all
{
	t_philo				*philo;
	long int			n_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			get_time;
	long long int		time_start;
	long int			dead;
	pthread_mutex_t		died;
	pthread_mutex_t		print;
}				t_all;

void			init(char **argv, t_all *all);
void			init_philo(t_all *all);
int				ft_atoi(const char *str);
int				to_sleep(t_philo *philo);
int				to_think(t_philo *philo);
void			usleep_time(int time);
long long int	get_time(void);
int				to_eat(t_philo *philo);
int				is_dead(t_philo *philo);

#endif