#include "push_swap.h"

int    findmax(t_push_list **stack, t_push_list **stack_b)
{

    t_push_list	*temp;
	t_push_list	*temp2;
    int i;

	temp = *stack_b;
	temp2 = *stack_b;
    i = 0;
    while (temp2)
	{
		if (temp2->next == NULL)
		{
			if (temp->index < temp2->index)
				i++;
			else if (i == 0)
				return (temp->index);
			else
			{
				temp = temp->next;
				temp2 = *stack;
				i = 0;
			}
		}
		if (temp->index < temp2->index)
			i++;
		temp2 = temp2->next;
	}
	return (0);
}

int    findmax_next(t_push_list **stack_b, int res2)
{

    t_push_list	*temp_b;
    int i;

	temp_b = *stack_b;
    i = 0;
    while(temp_b)
    {
        if(temp_b->index == res2)
            return (i);
        temp_b = temp_b->next;
        i++;
    }
    return (0);
}

void    sort_b(t_push_list **stack, t_push_list **stack_b)
{
    int res;
    int res2;
    
    res = findmax(stack, stack_b);
    res2 =  res - 1;
    send(stack_b, stack, 'a');
    printf("EL RESULTAT ES: %d\n", res2);
    findmax_next(stack_b, res2);


}