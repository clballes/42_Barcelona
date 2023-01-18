#include "push_swap.h"

int min(t_push_list **stack, int i, int j)
{
    t_push_list *temp;
    t_push_list *temp2;

    temp = *stack;
    temp2 = *stack;

    while (temp2)
    {
        if (temp2->next == NULL)
            {
                if (temp->index > temp2->index)
                    i++;
                if (i == 0)
                   return(j);
                else
                {
                    temp = temp->next;
                    temp2 = *stack;
                    i = 0;
                    j++;
                }
            }
        if (temp->index > temp2->index)
            i++;
        temp2 = temp2->next;     
    }
    return(0);
}