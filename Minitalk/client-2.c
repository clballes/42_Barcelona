/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:21:25 by clballes          #+#    #+#             */
/*   Updated: 2022/10/04 16:31:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char*);
int	ft_takesms(int pid, unsigned char str)
{
	int	octet;
	int c;

	octet = 8;
	c = 0;
	while (octet--)
	{
		str & 1;
		c = str;
			if (c == 1)
			{
				kill(pid, SIGUSR1); //envia de esquerra a dreta
				printf("Envia numero 1\n");
			}
			else	//envia 0
				kill(pid, SIGUSR2);
		c >> 1;
	}
	return(0);	
}	


int	main(int argc, char **argv)
{
	if (argc != '\0')
		ft_takesms(ft_atoi(argv[1]), *argv[2]);
	return (0);
}