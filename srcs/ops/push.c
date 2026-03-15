#include "ops.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;             
	*src = (*src)->next;      
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;       
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;             
	(*dst)->prev = NULL;
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(b, a); 
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, bool print)
{
	push(a, b); 
	if (print)
		write(1, "pb\n", 3);
}
