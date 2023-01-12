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

void    swap(t_push_list **stack, char c){

    t_push_list *first;
    t_push_list *second;
    //decalar principalment
    first = *stack;
    second = first->next;
    //fer el swap de nodes
    first->next = second->next;
    first->previous = second;
    second->next = first;
    second->previous = NULL;
    *stack = second;
    // print(stack);
    printf(" vengo de operaciones: s%c\n", c);
}
void top_rotate(t_push_list **stack, char c){

    t_push_list *bottom;
    t_push_list *top;
    t_push_list *second;

    top = *stack;
    bottom = ft_push_lstlast(top);
    second = top->next;
    second->previous = NULL;
    *stack = second;
    top->next = NULL;
    top->previous = bottom;
    bottom->next = top;
    // print(stack);
    printf(" vengo de operaciones: r%c\n", c);
}

void    bottom_rotate(t_push_list **stack, char c){
    t_push_list *bottom;
    t_push_list *top;

    top = *stack;
    bottom = ft_push_lstlast(top);

    bottom->previous->next = NULL;
    top->previous = bottom;
    bottom->next = top;
    print(&bottom);
    bottom->previous = NULL;
    top->next = top->next->next;
    *stack = bottom;
    printf(" vengo de operaciones: rr%c\n", c);
}

// void send(t_push_list **stack_A, t_push_list **stack_B){
    
//     t_push_list *top_A;
//     t_push_list *top_B;

//      top_A = *stack_A;
//      top_B = *stack_B;

//      if(top_A = NULL){
//         top_B->next = top_A;
//         *stack_A = top_B;
//         top_B->next->next = NULL;
//         top_A->previous->next = NULL;
//         B->previous = NULL;
//         A->previous = B;
//      }
// }

void print(t_push_list **stack) {
    t_push_list *temp;
    temp = *stack;

   	while ( temp != NULL) {
        printf("%d\n ", temp->value);
        temp = temp->next;
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