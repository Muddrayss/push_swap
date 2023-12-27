# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 13:59:13 by egualand          #+#    #+#              #
#    Updated: 2023/12/09 14:26:16 by egualand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c create_stack.c perform_operation.c push_stack.c \
       rotate_stack.c swap_stack.c reverse_stack.c sort_stack.c \
       print_list.c operations_count.c operations_count_2.c find_min.c \
       find_max.c perform_operations.c ft_error.c sort_two.c \
       sort_three.c sort_four.c sort_five.c ft_free_matrix.c

BONUS_DIR = ./bonus
SRCS_BONUS =	$(BONUS_DIR)/checker_bonus.c \
							$(BONUS_DIR)/ft_error_bonus.c \
            	$(BONUS_DIR)/perform_operation_bonus.c \
             	$(BONUS_DIR)/create_stack_bonus.c \
						 	$(BONUS_DIR)/get_next_line_bonus.c \
             	$(BONUS_DIR)/push_stack_bonus.c \
							$(BONUS_DIR)/rotate_stack_bonus.c \
             	$(BONUS_DIR)/swap_stack_bonus.c \
							$(BONUS_DIR)/reverse_stack_bonus.c \
							$(BONUS_DIR)/ft_free_matrix_bonus.c \
							$(BONUS_DIR)/print_list_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = .
INCLUDES_BONUS = $(BONUS_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
BONUS_NAME = checker

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)

# Main targets
all: $(NAME)

$(LIBFT_LIB):
		@make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
		@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -L $(LIBFT_DIR) -lft -o $(NAME)
		@echo "Compilation of push_swap done!"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT_LIB)
		@$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(INCLUDES_BONUS) -L $(LIBFT_DIR) -lft -o $(BONUS_NAME)
		@echo "Compilation of checker done!"

# Pattern rules
%.o: %.c
		@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# Cleaning rules
clean:
		@$(RM) $(OBJS) $(OBJS_BONUS)
		@$(MAKE) -C $(LIBFT_DIR) clean
		@echo "Cleaning of push_swap done!"

fclean: clean
		@$(RM) $(NAME) $(BONUS_NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean
		@echo "Full cleaning of push_swap done!"

re: fclean all

.PHONY: all clean fclean re bonus