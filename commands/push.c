#include "../push_swap.h"

static void push(t_stack_node **src, t_stack_node **dst)
{
    t_stack_node *tmp;

    if (!(*src))
        return ;
    tmp = *src;
    *src = tmp->next;
    if (*src)
        (*src)->prev = NULL;
    tmp->prev = NULL;
    if (!(*dst))
    {
        *dst = tmp;
        tmp->next = NULL; // nécessaire
    }
    else
    {
        tmp->next = *dst;
        tmp->next->prev = tmp; // ne fonctionne pas sans ça
        tmp->prev = (*dst)->prev; // fonctionne avec et sans
        *dst = tmp;
    }
}

void    pa(t_stack_node **b, t_stack_node **a)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}