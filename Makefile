# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egualand <egualand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 13:59:13 by egualand          #+#    #+#              #
#    Updated: 2023/11/16 17:25:06 by egualand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c create_stack.c perform_operation.c push_stack.c \
		rotate_stack.c swap_stack.c reverse_stack.c sort_stack.c \
		print_list.c
		
OBJS = $(SRCS:.c=.o)

INCLUDES = .

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
