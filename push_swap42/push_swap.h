/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:39 by clballes          #+#    #+#             */
/*   Updated: 2022/11/04 18:19:20 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "LIBFT/libft.h"

void	ft_check(int argc, char **argv);
void	write_error(void);
void	ft_maxmin_int(char **argv, int argc, int j);
void	ft_comparedigit(char **argv, int arc, int j);
int		take_numbers(int argc, char **argv);
#endif
