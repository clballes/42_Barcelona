/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:09:40 by clballes          #+#    #+#             */
/*   Updated: 2022/09/05 15:58:50 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
static char	*ft_fill_storage(char *storage, int fd);
char	*ft_get_a_line(char *storage);

// funcion principal
char	*get_next_line(int fd)	
{
	static char *storage = NULL;
	if (storage == NULL)
		storage = strdup("");
	char *line;
	storage = ft_fill_storage(storage, fd);
	line = ft_get_a_line(storage);
	return (line);
}

static char *ft_fill_storage(char *storage, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		cont;

	cont = 1;
	while (!ft_strchr(buffer, '\n') && cont > 0)
	{	
		cont = read(fd, buffer, BUFFER_SIZE);
		if (cont == -1)
			return (NULL);
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}

char	*ft_get_a_line(char *storage)
{
	int	i;
	char *line = (char *)malloc(sizeof(line + 1));
	
	i = 0;
	while (storage[i] != '\n')	
	{
		line[i] = storage[i];
		i++;
	}
	line [i] = '\0';
	return (line);
}