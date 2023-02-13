#include "push_swap.h"

void	print_swap(t_push_list **stack, char c)
{
	swap (stack);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (c == 'a')
		write(1, "sa\n", 3);
}

void	print_rotate(t_push_list **stack, char c)
{
	top_rotate (stack);
	if (c == 'b')
		write(1, "rb\n", 3);
	if (c == 'a')
		write(1, "ra\n", 3);
}

int	print_rotate_both(t_push_list **stack, t_push_list **stack_b)
{
	if (!*stack_b)
	{
		printf("putoooo\n");
		return (0);
	}
	top_rotate (stack);
	top_rotate (stack_b);
	write(1, "rr\n", 3);
	return (1);
}

void	print_rev_rotate(t_push_list **stack, char c)
{
	bottom_rotate (stack);
	if (c == 'b')
		write(1, "rrb\n", 4);
	if (c == 'a')
		write(1, "rra\n", 4);
}
