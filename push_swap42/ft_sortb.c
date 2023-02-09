#include "push_swap.h"

int	cont_stackb(t_push_list **stack, t_push_list **stack_b, int max)
{
	t_push_list	*temp_b;
	int			cont;

	cont = 0;
	temp_b = *stack_b;
	if (max == 2)
	{
		if (temp_b->index < temp_b->next->index)
			swap (stack_b, 'b');
		send(stack_b, stack, 'a');
		send(stack_b, stack, 'a');
	}
	while (temp_b)
	{
		if (temp_b->index == max)
			return (cont);
		cont++;
		temp_b = temp_b->next;
	}
	return (0);
}

int	rotate_b(t_push_list **stack, t_push_list **stack_b, int max)
{
	int	size;
	int	cont;

	size = ft_push_lstsize(*stack_b);
	cont = cont_stackb(stack, stack_b, max);
	if (cont == 0)
		send(stack_b, stack, 'a');
	else if (cont >= (size / 2))
	{
		cont = max - cont;
		while (cont--)
			bottom_rotate (stack_b, 'b');
		send (stack_b, stack, 'a');
	}
	else if (cont < (size / 2))
	{
		while (cont--)
			top_rotate (stack_b, 'b');
		send (stack_b, stack, 'a');
	}
	return (0);
}

void	sort_b(t_push_list **stack, t_push_list **stack_b,
		t_push_list *temp_b, t_push_list *temp)
{
	int	max;
	int	size;
	int	cont_size;
	int	i;

	cont_size = 0;
	size = ft_push_lstsize(*stack_b);
	i = findmax(stack_b);
	temp_b = *stack_b;
	while (i-- && temp_b && i > 2)
	{
		if (check_cont(stack, stack_b, max) == 0)
		{
			max = findmax (stack_b);
			rotate_b (stack, stack_b, max);
			temp_b = *stack_b;
			temp = *stack;
		}
		i = max;
	}
	max -= 1;
	if (max == 2)
		cont_stackb (stack, stack_b, max);
	print_list(stack, stack_b);
}

int	check_cont(t_push_list **stack, t_push_list **stack_b, int max)
{
	int	cont_nxt;
	int	cont_nxt2;

	cont_nxt = cont_stackb(stack, stack_b, max);
	cont_nxt2 = cont_stackb(stack, stack_b, (max - 1));
	if (cont_nxt == 0)
		return (0);
	if (cont_nxt == cont_nxt2 - 1)
	{
		while (cont_nxt--)
			top_rotate (stack_b, 'b');
		ft_sendx2(stack_b, stack);
		return (1);
	}
	else if (cont_nxt == cont_nxt2 + 1)
	{
		while (cont_nxt2--)
			top_rotate(stack_b, 'a');
		ft_sendx2(stack_b, stack);
		swap (stack, 'a');
		return (1);
	}
	else
		return (0);
}

int	findmax(t_push_list **stack_b)
{
	t_push_list	*temp;
	t_push_list	*temp2;

	temp = *stack_b;
	temp2 = *stack_b;
	while (temp2)
	{
		if (temp2->index > temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp->index);
}
