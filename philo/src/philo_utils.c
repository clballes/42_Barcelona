/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:59:35 by clballes          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:36 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (str[1] == '-' || str[1] == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

long long int	get_time(void)
{
	struct timeval	time;
	long long int	current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

void	usleep_time(int time)
{
	long long int	current_time;

	current_time = get_time();
	while (time > get_time() - current_time)
	{
		if (usleep(1) == -1)
			return ;
	}
	return ;
}

int	is_not_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= 48 && argv[i] <= 57)
			i++;
		else
			return (1);
	}
	return (0);
}

int	max_int(char *argv)
{
	int	max;

	if (ft_strlen(argv) > 11)
		return (1);
	max = ft_atoi(argv);
	if (max < 0)
		return (1);
	else
		return (0);
}
