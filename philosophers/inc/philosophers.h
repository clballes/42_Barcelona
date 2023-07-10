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
	int	r_fork;
	int	l_fork;
}				t_philo;

typedef struct s_all
{
	t_philo	*philo;
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}				t_all;

int	ft_atoi(const char *str);
#endif