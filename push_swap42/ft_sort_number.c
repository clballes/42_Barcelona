/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:54 by clballes          #+#    #+#             */
/*   Updated: 2023/01/12 13:53:25 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_push_list **stack, char c)
{
    t_push_list *pointer;
    int index;
    int index2;
    int index3;

    pointer = *stack;
    index = pointer->index;
    index2 = pointer->next->index;
    index3 = pointer->next->next->index; 
    if ((index3 > index2) && (index3 > index) && (index > index2)) //case1
        swap(&pointer, c);
    else if ((index3 < index2) && (index2 < index) && (index > index3)){ //case2
        swap(&pointer, c);
        bottom_rotate(&pointer, c);
    }
    else  if((index > index2) && (index > index3) && (index2 < index3))//case3
        top_rotate(&pointer, c);
    else if((index2 > index) && (index2 > index3)){ //case4
        if(index < index3){
            swap(&pointer, c);
            top_rotate(&pointer, c);
        }
        else //case5
            bottom_rotate(&pointer, c);
    }
}

void    sort_five(t_push_list **stack, t_push_list **stack_b)
{
    char c;
    c = 'a';
    if (stack){
        if (c){
            c = 'b';
            send(stack, stack_b, c);
            send(stack, stack_b, c);
        }
        c = 'a';
        swap(stack, c);
        top_rotate(stack, c);

        }
        send(stack, stack_b, c); ////send to b stack
        print_list(stack, stack_b);
        //send to b stack
        top_rotate(stack, c);
}