/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:17:47 by clballes          #+#    #+#             */
/*   Updated: 2022/07/14 15:41:22 by clballes         ###   ########.fr       */
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
int		ft_printf_string(char *str);
int		ft_printf_pointer(void *p);
int		ft_printf_decimal(signed int n);
int		ft_printf_int(int n);
int		ft_printf_unsigned_decimal(unsigned int n);
int		ft_printf_hexad_low(unsigned int j);
int		ft_printf_hexad_upp(unsigned int i);
int		ft_printf_percent(void);
char	*ft_hexadecimal(unsigned long long int j);
int		ft_putchar(char c);
int		ft_put_hex(unsigned long long p);
char	ft_numbers_to_letters(unsigned long long int hexadecimal);
int		ft_hexadecimal_len(unsigned long long int j);
char	*ft_create_str(unsigned long long int j);
#endif
