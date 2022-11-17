/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:00:06 by clballes          #+#    #+#             */
/*   Updated: 2022/07/01 18:21:54 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char	*ft_hexadecimal(int j);
int		ft_printf_pointer(void * p)
{
	char *str;
	//void	j; //guardar adressa
	int cont;
	cont = 0;
	
	p = &str;
	printf("%p", str);
	//write(filedescriptor, &j, sizeof(p));
	printf("%s", str);
	//str = ft_hexadecimal(i);
	while (str[cont] != '\0')
		cont++;
	return(cont);
}
int main()
{
	void *p;
	int	j;
	p = &j;
	
	j = ft_printf_pointer(p);
	//printf("%p", p);
}
