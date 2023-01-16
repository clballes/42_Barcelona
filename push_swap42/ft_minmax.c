#include "push_swap.h"

void    min(t_push_list **stack)
{
    t_push_list *temp;
    // int index;

    temp = *stack;
    // index = temp->index;
    while(temp)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
                                                                                                                                                                                                                                                                                     
            printf("el indice es: %d", temp->index);
        }
    }
}                                      