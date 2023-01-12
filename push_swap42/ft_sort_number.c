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

void    sort_three(t_push_list **stack, char c){

    t_push_list *pointer;
    int index;
    int index2;
    int index3;

    pointer = *stack;
    index = pointer->index;
    index2 = pointer->next->index;
    index3 = pointer->next->next->index;
    
    if ((index3 > index2) && (index3 > index) && (index > index2)) // funciona perf case 1
        swap(&pointer, c);
    if ((index3 < (index2) && (index2 < index))){
        swap(&pointer, c);
        print(&pointer);
        // bottom_rotate(&pointer, c); //segmentattion fault i no mesta funcionant del tot be
        }
    if((index > index2) && (index > index3)){ //funciona perfecte case 3
        top_rotate(&pointer, c);
        }
    if((index2 > index) && (index2 > index3)){ //funciona perf case4
        if(index < index3){
            swap(&pointer, c);
            top_rotate(&pointer, c);
            print(&pointer);
        }
        else
            printf("heyyu");
            //rotate element rra
           // bottom_rotate(&pointer, c);
    }
}

void    sort_five(t_push_list **stack, t_push_list **stack_b){

    t_push_list *pointer_a;
    t_push_list *pointer_b;
    pointer_a = *stack;
    pointer_b = *stack_b;
        printf("holaaa");

    // if (pointer_a){
    //     //llamar a pb
    //     //llamar a pb
    // }
    // pointer_a = sort_three(&stack);
    // pointer_b = //llamar pa; 
    // pointer_a = //ra;
    // pointer_b = //pa
}
