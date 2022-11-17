/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:12:27 by clballes          #+#    #+#             */
/*   Updated: 2022/07/28 18:10:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char	*get_next_line(int fd);
int	main()
{
	int fd;
	char *line;

	fd = open("./hola.txt", O_RDONLY);
	line =	get_next_line(fd);
//	printf("the file has open\n");
	printf("la line del main es: %s\n", line);
	return (0);
}
