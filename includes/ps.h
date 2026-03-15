#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

/* --- Structure --- */
typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* --- Main / Init / Exit (srcs/main/) --- */
void	check_args(int argc, char **argv);
void	init_stack(t_node **stack_a, int argc, char **argv);
void	free_stack(t_node **stack);
void	error_exit(t_node **stack_a, t_node **stack_b);

/* --- Parsing (srcs/parsing/) --- */
void	parse_input(int argc, char **argv, t_node **stack_a);
bool	is_valid_num(char *str);
bool	has_duplicate(t_node *stack, int num);

/* --- Utils (srcs/utils/) --- */
int		stack_size(t_node *stack);
bool	is_sorted(t_node *stack);
t_node	*get_last_node(t_node *stack);
void	stack_add_back(t_node **stack, t_node *new);
t_node	*stack_new(int value);

#endif
