#include "push_swap.h"

static void find_a_targets(t_stack_node *a, t_stack_node *b)
{
    long            csn;
    t_stack_node    *target;
    t_stack_node    *bh;

    while (a)
    {
        csn = INT_MIN; // diff long
        bh = b;
        while (bh)
        {
            if ((bh->n > csn) && (bh->n < a->n))
            {
                csn = bh->n;
                target = bh;
            }
            bh = bh->next;
        }
        if (csn == INT_MIN)
            a->target = max(b);
        else
            a->target = target;
        a = a->next;
    }
}

static void a_cost(t_stack_node *a, t_stack_node *b)
{
    int     la;
    int     lb;

    la = lstlen(a);
    lb = lstlen(b);
    while(a)
    {
        a->cost = a->index;
        if (a->after_median)
            a->cost = la - a->index;
        if(!(a->target->after_median))
            a->cost += a->target->index;
        else
            a->cost += lb - a->target->index;
        a = a->next;
    }
}

static void cheapest_cost(t_stack_node *a)
{
    int             cheapest_value;
    t_stack_node    *cheapest_node;

    if (a == NULL)
        return ;
    cheapest_value = INT_MAX;
    while(a)
    {
        if (a->cost < cheapest_value)
        {
            cheapest_value = a->cost;
            cheapest_node = a;
        }
        a = a->next;
    }
    cheapest_node->cheapest_cost = 1;
}

void    index_median(t_stack_node *stack)
{
    int     i;
    int     median;

    i = 0;
    median = lstlen(stack) / 2;
    while(stack)
    {
        stack->index = i;
        if (i <= median)
            stack->after_median = 1;
        else
            stack->after_median = 0;
        stack = stack->next;
        i++;
    }
}

void    init_a(t_stack_node *a, t_stack_node *b)
{
    index_median(a);
    index_median(b);
    find_a_targets(a, b);
    a_cost(a, b);
    cheapest_cost(a);
}