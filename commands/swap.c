#include "../push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (lstlen(*stack) < 2)
		return	;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

void    sa(t_stack_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}