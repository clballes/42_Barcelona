#include "push_swap.h"

void    sort_hundred(t_push_list **stack, t_push_list **stack_b, int half)
{
    t_push_list *temp;
    // t_push_list *last;
        t_push_list *last2;


    int cont1;
    int cont2;
    // last = readlist(stack, half);
    // printf("LAST ES: %d\n", last->value);
    cont1 = 0;
    cont2 = 0;
    last2 = *stack_b;
    half = half / 2;
    temp = *stack;
    while (temp)
    {
        if (temp->index >= 0 && temp->index <= 3)
            {
                cont2 = readlist(stack, half);
                compare(stack, stack_b, cont1, cont2);
            }
        else
        {
            temp = temp->next;
            cont1++;
        }
    }
    // print_list(stack, stack_b);
}

void    compare(t_push_list **stack, t_push_list **stack_b, int cont1, int cont2)
{
    t_push_list *temp;

    temp = *stack;
    if (cont1 > cont2)
        ft_sort_chunk_rra(stack, stack_b, cont1);
    else
        ft_sort_chunk_ra(stack, stack_b, cont2);
    temp = *stack;
}

// int   chunk(t_push_list **stack, t_push_list **stack_b,int half, int cont)
// {
//     if (cont < half) //temp major que la meitat
//             cont = ft_sort_chunk_ra(stack, stack_b, cont);
//     else if (cont >= half) //temp menor q la meitat
//     {
//                 cont = (half * 2) - cont;
//                 cont = ft_sort_chunk_rra(stack, stack_b, cont);
//     }
//     return (cont);
// }

int readlist(t_push_list **stack, int half)
{
    t_push_list *temp;
    t_push_list *last;
    int cont2;

    cont2 = 0;
    temp = *stack;
    while (half--)
    {
        temp = temp->next;
        if(temp->next == NULL)
            break;
    }
    last = temp;
    while (last)
    {
        if (last->index >= 0 && last->index <= 3)
            return (cont2);
        else
        {
            last = last->next;
            cont2++;
        }
    }
    return (cont2);
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