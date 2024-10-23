#include "push_swap.h"

static void add_node(t_stack_node **stack, int nb)
{
    t_stack_node    *node;
    t_stack_node    *last;

    node = malloc(sizeof(t_stack_node));
    if (node == NULL)
        return ;
    node->cheapest_cost = 0;
    node->n = nb;
    node->next = NULL;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last = ft_lstlast(*stack);
        last->next = node;
        node->prev = last;
    }
}

static void fill_a(t_stack_node **a, char **av)
{
    int     i;

    i = 0;
    while(av[i])
    {
        if (error_input(av[i]) || doubles(*a, ft_atol(av[i])) ||
            (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN))
        {
            free_stack(a);
            error_msg();
        }
        add_node(a, ft_atol(av[i]));
        i++;
    }
}



int main(int ac, char **av)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if (ac == 2 && !av[1] && !av[1][0])
        return (0);
    if (ac == 2)
        av = ft_split(av[1], 32);
    fill_a(&a, av + 1);
    if (is_sorted(a) == 0)
    {
        if (lstlen(a) == 2)
            sa(&a);
        else if (lstlen(a) == 3)
            sort_3(&a);
        else
            main_algo(&a, &b);
    }
    if (ac == 2)
        free_split(av);
    free_stack(&a);
    return (0);
}