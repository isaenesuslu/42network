NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

# --- Klasörler ---
SRCS_DIR    = srcs/
OBJS_DIR    = objs/

# --- Modüller ---
MAIN_FILES  = main/main.c main/init.c main/exit.c
PARS_FILES  = parsing/parser.c parsing/check.c parsing/split.c
OPS_FILES   = ops/push.c ops/swap.c ops/rotate.c ops/rrotate.c
ALGO_FILES  = algo/turk.c algo/sort.c algo/cost.c
UTIL_FILES  = utils/stack.c utils/list.c utils/algo.c utils/algo_utils.c

SRC_FILES   = $(MAIN_FILES) $(PARS_FILES) $(OPS_FILES) $(ALGO_FILES) $(UTIL_FILES)

SRCS        = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS        = $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))

# --- Kurallar ---
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
