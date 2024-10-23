#include "push_swap.h"

//change
int lstlen(t_stack_node *stack)
{
    if (stack == NULL)
        return (0);
    else
        return (1 + lstlen(stack->next));
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;

    if (*stack == NULL)
        return ;
    while(*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

int is_sorted(t_stack_node *stack)
{
    if (stack == NULL)
        return (1);
    while (stack->next)
    {
        if (stack->n > stack->next->n)
            return (0);
        stack = stack->next;
    }
    return (1);
}

long    ft_atol(char *s)
{
    int     i;
    int     sign;
    long    res;

    i = 0;
    res = 0;
    sign = 1;
    while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
        i++;
    if (s[i] && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] && s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return (res * sign);

}

t_stack_node    *ft_lstlast(t_stack_node *stack)
{
    if (stack == NULL)
        return (NULL);
    while(stack->next)
        stack = stack->next;
    return (stack);
}