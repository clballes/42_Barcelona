#include "push_swap.h"

void    sort_hundred(t_push_list **stack, t_push_list **stack_b, int len)
{
    t_push_list *temp;
    t_push_list *temp3;

    int i;
    temp = *stack;
    //descobrim la meitat de la llista quin numero tenim
    i = len / 2;
    while(i--)
        temp = temp->next;
    temp3 = temp;
    printf("temp3 es: %d\n", temp3->value);
    chunk(stack, stack_b, temp3);
}
void    chunk(t_push_list **stack, t_push_list **stack_b, t_push_list *temp3)
{
    t_push_list *temp;
    int cont;

    cont = 0;
    temp = *stack;
    while (temp < temp3) //temp major que la meitat
    {
        if (temp->next == NULL)
            break;
        if (temp->index > 0 && temp->index <= 5)
        {
            cont = ft_sort_chunk_ra(stack, stack_b, cont);
            temp = *stack;
        }
        else
            temp = temp->next;
    cont++;
    }
    print_list(stack, stack_b);

}

int    ft_sort_chunk_ra(t_push_list **stack, t_push_list **stack_b, int cont)
{
    t_push_list *temp;

    temp = *stack;
    while (cont--)
        top_rotate(stack, 'a');
    send(stack, stack_b, 'b'); 
    return(-1);
}