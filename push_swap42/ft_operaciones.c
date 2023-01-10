/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operaciones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:22 by clballes          #+#    #+#             */
/*   Updated: 2023/01/10 12:34:24 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void swap(t_push_list **stack)
{
    t_push_list *first;
    t_push_list *second;

    first = *stack;
    second = first->next;
    second = first;
    second = second->previous = NULL;
    first = first->next;
}

// void    bottomrotate(t_push_list **stack)
// {
//     t_push_list *p;
//     t_push_list *top;

//     p = *stack;
//     while(p)
//     {
//         if(p->next == NULL) //aqui estic al final de tot
//         {
//             p->previous = NULL;
//             p->next = top;
//             printf("el ultimo numero: %d\n", p->value);
//             break;
//         }
//         else{
//             printf("%d\n", p->value);   
//             p = p->next;
//         }
//     }
// }

void toprotate(t_push_list **stack)
{
    t_push_list *bottom;
    t_push_list *top;

    top = *stack;
    top->previous = NULL;
    bottom = *stack;

    while(bottom)
    {
        if(bottom->next == NULL) //aqui estic al final de tot
        {
            bottom->next = top;
            printf("el ultimo numero: %d\n", top->value);
            break;
        }
        else{
            bottom = bottom->next;
        }
    }
    
}

// void    print_list (t_element **list_a, t_element **list_b)
// {
//     t_element *temp_a;
//     t_element *temp_b;
//     temp_a = *list_a;
//     temp_b = *list_b;
//     while (temp_a)
//     {
//         printf("valor en lista_1:%d, valor en index:%d\n", temp_a->value, temp_a->index);
//         temp_a = temp_a->next;
//     }
//     printf("----------------------------------------\n");
//     while(temp_b)
//     {
//         printf("valor en lista_2:%d, valor en index:%d\n", temp_b->value, temp_b->index);
//         temp_b = temp_b->next;
//     }
// }