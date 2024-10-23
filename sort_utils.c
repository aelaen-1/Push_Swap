#include "push_swap.h"

void            target_on_top(t_stack_node **stack, t_stack_node *target, char stack_name)
{
    if (stack == NULL)
        return ;
    
    while (*stack != target)
    {
        if (stack_name == 'a')
        {
            if (target->after_median)
                rra(stack);
            else
                ra(stack);
        }
        if (stack_name == 'b')
        {
            if (target->after_median)
                rrb(stack);
            else
                rb(stack);
        }
    }
}

t_stack_node    *cheapest_node(t_stack_node *stack)
{
    t_stack_node    *tmp;

    if (stack == NULL)
        return (NULL);
    tmp = stack;
    while (tmp)
    {
        if (tmp->cheapest_cost == 1)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void            rotate_til_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while ((*a != cheapest) && (*b != cheapest->target))
        rr(a, b);
    index_median(*a);
    index_median(*b);
}

void            r_rotate_til_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while ((*a != cheapest) && (*b != cheapest->target))
        rrr(a, b);
    index_median(*a);
    index_median(*b);
}