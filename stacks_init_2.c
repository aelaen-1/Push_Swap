#include "push_swap.h"

static void find_b_targets(t_stack_node *a, t_stack_node *b)
{
    long            chn;
    t_stack_node    *target;
    t_stack_node    *ah;

    while (b)
    {
        ah = a;
        chn = INT_MAX; // diff long
        while(ah)
        {
            if ((ah->n < chn) && (ah->n > b->n))
            {
                chn = ah->n;
                target = ah;
            }
            ah = ah->next;
        }
        if (chn == INT_MAX)
            b->target = min(a);
        else
            b->target = target;
        b = b->next;
    }
}

void    init_b(t_stack_node *a, t_stack_node *b)
{
    index_median(b);
    index_median(a);
    find_b_targets(a, b);
}