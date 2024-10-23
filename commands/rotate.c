#include "../push_swap.h"

static void	rotate_to_top(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void    ra(t_stack_node **a)
{
    rotate_to_top(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack_node **b)
{
    rotate_to_top(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack_node **a, t_stack_node **b)
{
    rotate_to_top(a);
    rotate_to_top(b);
    write(1, "rr\n", 3);
}

