#include "push_swap.h"

void    sort_hundred(t_push_list **stack, t_push_list **stack_b, int half)
{
    t_push_list *temp;
    int cont;

    cont = 0;
    half = half / 2;
    temp = *stack;
    while (temp)
    {
        if (temp->index >= 0 && temp->index <= 3)
            {
                cont = chunk(stack, stack_b, half, cont);
                temp = *stack;
            }
        else
        {
            temp = temp->next;
            cont++;
        }
    }
    print_list(stack, stack_b);
}

int   chunk(t_push_list **stack, t_push_list **stack_b,int half, int cont)
{
    if (cont < half) //temp major que la meitat
            cont = ft_sort_chunk_ra(stack, stack_b, cont);
    else if (cont >= half) //temp menor q la meitat
                cont = ft_sort_chunk_rra(stack, stack_b, cont);
    return (cont);
}

int    ft_sort_chunk_rra(t_push_list **stack, t_push_list **stack_b, int cont)
{
   while (cont--)
        bottom_rotate(stack, 'a');
    send(stack, stack_b, 'b'); 
    return(0);
}

int    ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b, int cont)
{
    while (cont--)
        top_rotate(stack, 'a');
    send(stack, stack_b, 'b'); 
    return(0);
}