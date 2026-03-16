/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:48:42 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 12:02:33 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_mode
{
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE
}	t_mode;

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

/* Main & Control */
t_mode	ps_stack_init(t_node **stack_a, int argc, char **argv);
void	ps_free_all(t_node **stack);
void	ps_error_exit(t_node **stack_a, t_node **stack_b);
void	ps_dispatch_sort(t_node **a, t_node **b, int size);
void	ps_print_bench(int n);

/* Parsing & Validation */
t_mode	ps_parse_input(int argc, char **argv, t_node **stack_a);
bool	ps_check_number(char *str);
bool	ps_check_duplicates(t_node *stack, int num);
char	**ps_split(char const *s, char c);
long	ps_atoi(char *str);
int		ps_strcmp(const char *s1, const char *s2);
void	ps_free_args(char **args);

/* Stack Utils */
int		ps_get_size(t_node *stack);
bool	ps_is_sorted(t_node *stack);
void	ps_set_positions(t_node *stack);
t_node	*ps_get_last(t_node *stack);
t_node	*ps_node_new(int value);
void	ps_node_add_back(t_node **stack, t_node *new);

#endif
