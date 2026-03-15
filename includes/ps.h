#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

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

typedef enum e_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_mode;

/* --- Main / Init / Exit --- */
t_mode	ps_stack_init(t_node **stack_a, int argc, char **argv);
void	ps_free_all(t_node **stack);
void	ps_error_exit(t_node **stack_a, t_node **stack_b);

/* --- Parsing --- */
t_mode	ps_parse_input(int argc, char **argv, t_node **stack_a);
bool	ps_check_number(char *str);
bool	ps_check_duplicates(t_node *stack, int num);
char	**ps_split(char const *s, char c);
int		ps_strcmp(const char *s1, const char *s2);

/* --- Utils --- */
int		ps_get_size(t_node *stack);
bool	ps_is_sorted(t_node *stack);
void	ps_set_positions(t_node *stack);
t_node	*ps_get_last(t_node *stack);
void	ps_node_add_back(t_node **stack, t_node *new);
t_node	*ps_node_new(int value);

#endif
