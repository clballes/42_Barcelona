/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:40:50 by clballes          #+#    #+#             */
/*   Updated: 2022/10/04 17:42:09 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_strchr_get(char *s, int c);
char	*get_next_line(int fd);
char	*ft_protect(char *s1);
#endif
