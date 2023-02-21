/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:21:25 by clballes          #+#    #+#             */
/*   Updated: 2022/12/19 12:15:03 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../LIBFT/libft.h"
#include "../PRINTF/INC/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signo)
{
	static int	i = 0;

	if (signo == SIGUSR2)
		i++;
	if (ft_printf("\r\e I received [%d] bits", i) == -1)
		exit(-1);
	if (signo == SIGUSR1)
	{
		if (ft_printf("\r\e I received [%d] bits. Document Finished", i) == -1)
			exit(-1);
		exit(EXIT_SUCCESS);
	}
}

int	ft_takesms(int pid, unsigned char str)
{
	int	bit;
	int	mask;

	mask = 128;
	bit = 8;
	while (bit--)
	{
		if (str & mask)
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		usleep(400);
		mask >>= 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	signal(SIGUSR2, sig_handler);
	signal(SIGUSR1, sig_handler);
	if (argc == 3)
	{	
		while (argv[2][i] != '\0' && argc > 0)
		{	
			ft_takesms(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		ft_takesms(ft_atoi(argv[1]), argv[2][i]);
	}
	else
	{
		if (ft_printf("Not enough arguments!") == -1)
			exit(-1);
	}
	return (0);
}
