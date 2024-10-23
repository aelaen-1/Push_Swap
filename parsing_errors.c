#include "push_swap.h"

int     error_input(char *av)
{
    int     i;

    i = 0;
    if (!(av[0] == '+' || av[0] == '-' || (av[0] >= '0' && av[0] <= '9')))
        return (1);
    if ((av[0] == '+' || av[0] == '-') && !(av[1] >= '0' && av[1] <= '9'))
        return (1);
    i++;
    while(av[i])
    {
        if (!(av[i] >= '0' && av[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int     doubles(t_stack_node *stack, long nb)
{
    if (stack == NULL)
        return (0);
    while(stack)
    {
        if (stack->n == nb)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void    error_msg(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
}