/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:09:14 by clballes          #+#    #+#             */
/*   Updated: 2022/10/17 19:04:50 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../LIBFT/libft.h"
#include "../PRINTF/INC/ft_printf.h"

//int	g_byte;

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	byte = 0;

	(void)context;
	usleep(100);
	if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	if (sig == SIGUSR1)
	{
		c = c | 1;
		kill(info->si_pid, SIGUSR2);
	}
	byte++;
	if (byte == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		c = 0;
		byte = 0;
	}
	c <<= 1;
}

int	main(void)
{
	int					pid_t;
	struct sigaction	sig;

	//g_byte = 0;
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid_t = getpid();
	if (ft_printf("The PID is: %d\n", pid_t) == -1)
		exit (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
