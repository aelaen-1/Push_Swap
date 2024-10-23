#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h> // bool

typedef struct s_stack_node
{
    int     n;
    int     index;
    int     after_median;
    int     cheapest_cost;
    int     cost;
    struct s_stack_node *prev;
    struct s_stack_node *next;
    struct s_stack_node *target;
}   t_stack_node;

int     error_input(char *av);
int     doubles(t_stack_node *stack, long nb);
// char    **ft_split(char *s);
char	**ft_split(char *s, char c);
void    free_split(char **s);

void    index_median(t_stack_node *stack);
void    init_a(t_stack_node *a, t_stack_node *b);
void    init_b(t_stack_node *a, t_stack_node *b);


void            sort_3(t_stack_node **stack);
void            main_algo(t_stack_node **a, t_stack_node **b);
void            target_on_top(t_stack_node **stack, t_stack_node *target, char stack_name);
void            rotate_til_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void            r_rotate_til_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
t_stack_node    *cheapest_node(t_stack_node *stack);

int             lstlen(t_stack_node *stack);
void            free_stack(t_stack_node **stack);
int             is_sorted(t_stack_node *stack);
long             ft_atol(char *s);
t_stack_node    *ft_lstlast(t_stack_node *stack);
void            error_msg(void);

void    pa(t_stack_node **b, t_stack_node **a);
void    pb(t_stack_node **a, t_stack_node **b);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void    ss(t_stack_node **a, t_stack_node **b);

t_stack_node    *min(t_stack_node *stack);
t_stack_node    *max(t_stack_node *stack);

#endif