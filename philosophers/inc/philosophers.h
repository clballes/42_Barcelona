
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> 

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef struct s_philo
{
    int r_fork;
    int l_fork;
} t_philo;

typedef struct s_all
{
    t_philo *philo;
    int num_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
} t_all;

int	ft_atoi(const char *str);


#endif