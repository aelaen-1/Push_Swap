#include "../push_swap.h"

static void	rotate_to_bottom(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void    rra(t_stack_node **a)
{
    rotate_to_bottom(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b)
{
    rotate_to_bottom(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
	rotate_to_bottom(a);
    rotate_to_bottom(b);
    write(1, "rrr\n", 4);
}
