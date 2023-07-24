/* ************************************************************************** */
/*	                                                                         */
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

# define RESET	"\033[0m"
# define SLEEPING		"[%lld] \033[36mphilo  %s %d \033[33mis sleeping  %s\n"
# define DIED	"[%lld] \033[36mphilo  %s %d \033[31mis dead  %s\n"
# define L_FORK	"[%lld] \033[36mphilo  %s %d \033[32mhas taken left fork  %s\n"
# define R_FORK	"[%lld] \033[36mphilo  %s %d \033[32mmhas taken right fork  %s\n"
# define EATING	"[%lld] \033[36mphilo  %s %d \033[34mis eating  %s\n"
# define THINKING	"[%lld] \033[36mphilo  %s %d \033[35mis thinking  %s\n"
# define ATE	"[%lld] \033[36mphilo  %s %d \033[36meat all the times given  %s\n"

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
	int					n_eats;
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
void			print(int idx, t_philo *philo);
void			is_dead(t_all *all);
int				is_not_digit(char *argv);
int				max_int(char *argv);
void			free_mutex(t_all *all);

#endif