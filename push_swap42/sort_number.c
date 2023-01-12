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




void    sort_three(t_push_list **stack){
    
    t_push_list *pointer;

    pointer = *stack->index;
    pointer2 = *stack->index->next;
    pointer3 = *stack->index->next->next;

    
    if ((pointer3 > (pointer && pointer))){
        swap(&stack);
    }
    if ((pointer3 < (pointer && pointer)) ){
        if(pointer2 < pointer){
            swap(&stack);
            //rra movement
        }
        else
            //rra movement
    }
    if ((pointer3 > pointer2) && (pointer3 < pointer) ){
        //ra movement
    }
    if ((pointer3 < pointer2) && (pointer3 > pointer)){
        swap(&stack);
        //ra movement
    }
}

void    sort_five(t_push_list **stack, t_push_list **stack_b){

    t_push_list *pointer_a;
    t_push_list *pointer_b;


    pointer_a = *stack;
    if (pointer_a){
        //llamar a pb
        //llamar a pb
    }
    pointer_a = sort_three(&stack);
    pointer_b = //llamar pa; 
    pointer_a = //ra;
    pointer_b = //pa
}
