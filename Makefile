# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 13:59:13 by egualand          #+#    #+#              #
#    Updated: 2023/11/26 17:17:30 by egualand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c create_stack.c perform_operation.c push_stack.c \
		rotate_stack.c swap_stack.c reverse_stack.c sort_stack.c \
		print_list.c operations_count.c operations_count_2.c find_min.c \
		find_max.c perform_operations.c ft_error.c sort_two.c \
		sort_three.c sort_four.c sort_five.c ft_free_matrix.c
		
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

INCLUDES = .
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
RM = rm -f

NAME = push_swap

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)

all: $(NAME)

$(LIBFT_LIB):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re