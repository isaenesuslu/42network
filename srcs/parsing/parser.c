#include "ps.h"

static long	ps_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

static void	ps_free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	ps_validate_fill(t_node **stack_a, char **args, int argc)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		if (!ps_check_number(args[i]))
		{
			if (argc == 2)
				ps_free_args(args);
			ps_error_exit(stack_a, NULL);
		}
		num = ps_atoi(args[i]);
		if (num > INT_MAX || num < INT_MIN
			|| ps_check_duplicates(*stack_a, (int)num))
		{
			if (argc == 2)
				ps_free_args(args);
			ps_error_exit(stack_a, NULL);
		}
		ps_node_add_back(stack_a, ps_node_new((int)num));
		i++;
	}
}

static t_mode	ps_get_mode(char *arg, int *offset)
{
	if (ps_strcmp(arg, "--simple") == 0)
	{
		*offset = 2;
		return (MODE_SIMPLE);
	}
	if (ps_strcmp(arg, "--medium") == 0)
	{
		*offset = 2;
		return (MODE_MEDIUM);
	}
	if (ps_strcmp(arg, "--complex") == 0)
	{
		*offset = 2;
		return (MODE_COMPLEX);
	}
	if (ps_strcmp(arg, "--adaptive") == 0)
	{
		*offset = 2;
		return (MODE_ADAPTIVE);
	}
	return (MODE_ADAPTIVE);
}


t_mode	ps_parse_input(int argc, char **argv, t_node **stack_a)
{
	char	**args;
	t_mode	mode;
	int		off;

	mode = MODE_ADAPTIVE;
	off = 1;
	if (argc > 1 && argv[1][0] == '-')
		mode = ps_get_mode(argv[1], &off);
	if (argc == off + 1)
		args = ps_split(argv[off], ' ');
	else
		args = argv + off;
	if (!args || !args[0])
		return (mode);
	ps_validate_fill(stack_a, args, argc);
	if (argc == off + 1)
		ps_free_args(args);
	return (mode);
}

