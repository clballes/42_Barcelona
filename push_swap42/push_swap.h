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
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "LIBFT/libft.h"
# include <stdio.h>

typedef struct s_push_list
{
    int                value;
    int                index;
	struct s_push_list	*next;
    struct s_push_list	*previous;
}					t_push_list;

void	ft_check(int argc, char **argv);
void	write_error(void);
void	ft_maxmin_int(char **argv, int argc, int j);
void	ft_comparedigit(char **argv, int arc, int j);
void		take_numbers(t_push_list **stack, int num);
t_push_list	*ft_push_lstnew(int num);
t_push_list	*ft_push_lstlast(t_push_list *lst);
void	ft_push_lstadd_back(t_push_list **lst, t_push_list *new);
int	    ft_push_lstsize(t_push_list	*lst);
void    ft_setindex(t_push_list **stack);
//Operation functions
void    swap(t_push_list **stack, char c);
void    top_rotate(t_push_list **stack, char c);
void bottom_rotate(t_push_list **stack, char c);
void print(t_push_list **stack);
//Sort functions
void	sort(t_push_list **stack, t_push_list **stack_b, int i);
void    sort_three(t_push_list **stack, char c);
void    sort_five(t_push_list **stack, t_push_list **stack_b);
#endif