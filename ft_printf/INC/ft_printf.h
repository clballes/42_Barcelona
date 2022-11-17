/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:17:47 by clballes          #+#    #+#             */
/*   Updated: 2022/07/01 17:15:07 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printf_character(int c);
/*int		ft_printf_string;
int		ft_printf_pointer;
int		ft_printf_decimal;
int		ft_printf_int;
int		ft_printf_unsigned_decimal;
int		ft_printf_hexad_low;
int		ft_printf_hexad_upp;
int		ft_printf_percent;
*/
#endif
