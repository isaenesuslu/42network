# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iuslu <iuslu@student.42.fr>                +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2025/11/26 09:35:13 by iuslu             #+#    #+#              #
#    Updated: 2025/11/26 11:04:14 by iuslu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = src/main.c \
       src/parse_map_utils.c \
       src/parse_map.c \
       src/print.c \
       src/read_all.c \
       src/solver.c \
       src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
