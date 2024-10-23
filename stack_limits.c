#include "push_swap.h"

t_stack_node    *max(t_stack_node *stack)
{
    t_stack_node    *max;
    
    if (stack == NULL)
        return (NULL);
    max = stack;
    while(stack)
    {
        if (stack->n > max->n)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

t_stack_node    *min(t_stack_node *stack)
{
    t_stack_node    *min;

    if(stack == NULL)
        return (NULL);
    min = stack;
    while (stack)
    {
        if (stack->n < min->n)
            min = stack;
        stack = stack->next;
    }
    return (min);
}