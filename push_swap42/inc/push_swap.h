/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:39 by clballes          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:06 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>

typedef struct s_push_list
{
	int						value;
	int						index;
	struct s_push_list		*next;
	struct s_push_list		*previous;
}							t_push_list;
void		ft_check(int argc, char **argv);
void		write_error(void);
void		ft_maxmin_int(char **argv, int argc, int j);
void		ft_comparedigit(char **argv, int arc, int j);
void		take_numbers(t_push_list **stack, int num);
t_push_list	*ft_push_lstnew(int num);
t_push_list	*ft_push_lstlast(t_push_list *lst);
void		ft_push_lstadd_back(t_push_list **lst, t_push_list *new);
int			ft_push_lstsize(t_push_list	*lst);
void		ft_setindex(t_push_list **stack);
//Operation functions
void		swap(t_push_list **stack, char c);
void		top_rotate(t_push_list **stack, char c);
void		bottom_rotate(t_push_list **stack, char c);
void		check_three(t_push_list **stack);
//Sort functions
int			ft_checkindex(t_push_list **stack);
void		sort(t_push_list *stack, t_push_list *stack_b, int i);
void		sort_three(t_push_list **stack);
void		sort_five(t_push_list **stack, t_push_list **stack_b, int len);
void		sort_hundred(t_push_list **stack, t_push_list **stack_b, int beg);
void		print_list(t_push_list **list_a, t_push_list **list_b);
void		send(t_push_list **stack_a, t_push_list **stack_b, char c);
int			ft_sort(t_push_list **stack);
//encontrar el minmax
void		send_minimum(t_push_list **stack,
				t_push_list **stack_b, int resultado);
//create chunk
int			chunk(t_push_list **stack, t_push_list **stack_b,
				int cont, int end);
int			ft_sort_chunk_ra(t_push_list **stack,
				t_push_list **stack_b, int cont, int end);
int			ft_sort_chunk_rra(t_push_list **stack,
				t_push_list **stack_b, int cont, int end);
void		range_chunk(t_push_list **stack, t_push_list **stack_b,
				int end, int size_b);
void		sort_b(t_push_list **stack, t_push_list **stack_b,
				t_push_list	*temp_b, t_push_list *temp);
int			check_cont(t_push_list **stack, t_push_list **stack_b, int max);
int			findmax(t_push_list **stack_b);
int			find_contmin(t_push_list **stack);
int			rotate_b(t_push_list **stack, t_push_list **stack_b,
				int max, int cont);
int			cont_stackb(t_push_list **stack_b, int max);
void		sort_five_hundred(t_push_list **stack, t_push_list **stack_b);
//sorting 500 numbers
int			chunk500(t_push_list **stack, t_push_list **stack_b,
				int cont, int end);
void		range_chunk500(t_push_list **stack, t_push_list **stack_b,
				int end, int size_b);
void		range_sort(t_push_list **stack, t_push_list **stack_b, int len);
void		sort_5hundred(t_push_list **stack, t_push_list **stack_b, int end);
void		ft_reduce_moves(t_push_list **stack, int max);
void		ft_checka(t_push_list **stack);
void		rotate_op(t_push_list **stack, t_push_list **stack_b, int max);
void		rotate_op2(t_push_list **stack, t_push_list **stack_b, int max);
void		rotate_op_send(t_push_list **stack, t_push_list **stack_b, int max);
void		cont_rotate(t_push_list **stack, t_push_list **stack_b,
				int cont, int max);
void		check2(char **argv, int i, int j);
#endif
