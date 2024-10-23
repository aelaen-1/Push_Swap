#include "push_swap.h"

static void push_a_on_target(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *cheapest;

    cheapest = cheapest_node(*a);
    if (cheapest->after_median && cheapest->target->after_median)
        r_rotate_til_cheapest(a, b, cheapest);
    else if (!cheapest->after_median && !cheapest->target->after_median)
        rotate_til_cheapest(a, b, cheapest);
    target_on_top(a, cheapest, 'a');
    target_on_top(b, cheapest->target, 'b');
    pb(a, b);
}

//micro change (inversion a et b)
static void push_b_on_target(t_stack_node **b, t_stack_node **a)
{
    target_on_top(a, (*b)->target, 'a');
    pa(b, a);
}

//changes
static void head_min(t_stack_node **a)
{
    t_stack_node    *min_a;

    min_a = min(*a);
    while ((*a) ->n != min_a->n)
    {
        if ((min_a->after_median))
            rra(a);
        else
            ra(a);
    }
}

void    main_algo(t_stack_node **a, t_stack_node **b)
{
    int     la;

    la = lstlen(*a);
    if (la-- > 3 && !is_sorted(*a))
        pb(a, b);
    if (la-- > 3 && !is_sorted(*a))
        pb(a, b);
    while (la-- > 3 && !is_sorted(*a))
    {
        init_a(*a, *b);
        push_a_on_target(a, b);
    }
    sort_3(a);
    while (*b)
    {
        init_b(*a, *b);
        push_b_on_target(b, a);
    }
    head_min(a);
}

void    sort_3(t_stack_node **stack)
{
    t_stack_node    *highest;

    highest = max(*stack);
    if (*stack == highest)
        ra(stack);
    else if ((*stack)->next == highest)
        rra(stack);
    if (!is_sorted(*stack)) // change
        sa(stack);
}