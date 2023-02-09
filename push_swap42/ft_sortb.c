#include "push_swap.h"

int	cont_stackb(t_push_list **stack_b, int res2)
{
	t_push_list *temp_b;
	int cont;

	cont = 0;
	temp_b = *stack_b;
	while(temp_b)
	{
		if (temp_b->index == res2)
			return (cont);
		cont++;
		temp_b = temp_b->next;
	}
	return 0;
}

void    sort_b(t_push_list **stack, t_push_list **stack_b,	t_push_list	*temp_b)
{
    int max;
	int res;
	int cont;
	int size;

	size = ft_push_lstsize(*stack_b);
	send(stack_b, stack, 'a');
	temp_b = *stack_b;
	// print_list(stack, stack_b);
	while(temp_b && size--)
	{
		max = findmax(stack_b);
		res = check_cont(stack, stack_b, max); //check si tenim consecutius x estalviar moviments
		temp_b = *stack_b;
		if (res == 0)
		{
			size = ft_push_lstsize(*stack_b);
			max = findmax(stack_b);
			if(size == max)
			{
				top_rotate(stack_b, 'b');
				send(stack_b, 'b');
			}
			2.5
			else if((size / 2) > max)
			{
				//fariem contador
				cont--
				cont = cont_stackb(stack_b, max); 
				check_cont(stack, stack_b, max); //check si tenim consecutius x estalviar moviments

			}


			print_list(stack, stack_b);
			printf("la size:	-- %d\n", size);
			printf("el  max es:	-- %d\n", max);
		}

			//funcio top rotate o backrotate
	}
		// print_list(stack, stack_b);
}

int	check_cont(t_push_list **stack, t_push_list **stack_b, int max)
{
	int cont_max_nxt;
	int cont_max_nxt_nxt;

	cont_max_nxt = cont_stackb(stack_b, max); //contador del indice 19
	cont_max_nxt_nxt = cont_stackb(stack_b, (max - 1)); //contador indice 18
	if (cont_max_nxt == cont_max_nxt_nxt - 1) //aixo es x si tenim els indexs consecutius
	{
		while(cont_max_nxt--)
			top_rotate(stack_b, 'b');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
		return (1);
	}
	else if(cont_max_nxt == cont_max_nxt_nxt + 1) //si el petit consevutiu esta adalt
	{
		while(cont_max_nxt_nxt--)
			top_rotate(stack_b, 'a');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
		swap(stack, 'a');
		return (1);
	}
	else
		return (0);	
}

int    findmax(t_push_list **stack_b)
{
	t_push_list	*temp;
	t_push_list	*temp2;

	temp = *stack_b;
	temp2 = *stack_b;
	while(temp2)
	{
		if (temp2->index > temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp->index);
}
