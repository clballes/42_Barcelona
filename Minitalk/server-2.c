/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:09:14 by clballes          #+#    #+#             */
/*   Updated: 2022/10/04 14:49:53 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;
	(void)context;
	unsigned char c;
	int cont;
	char *byte;

	cont = 7;
	char *byte = '\0';
	if (!client_pid)
		client_pid = info->si_pid;	
	while (byte[cont] != '\0' && cont >= 0);
	{
		if (sig == SIGUSR1) //envia ite1
		{
			byte[cont] = 1;
		}
		if (sig == SIGUSR2) //envia bite0
		{
			byte[cont] = 0;
		}
		cont--;
	}	
	write(1, byte[cont], 1);
}
int		main()
{
	int pid_t;
	struct sigaction sig;

	sig.sa_sigaction = handler;
	sigfillset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig,  NULL);
	sigaction(SIGUSR2, &sig,  NULL);
	pid_t = getpid();
	printf("%d\n", pid_t);
	while(1)
	{
		pause();
	}
}