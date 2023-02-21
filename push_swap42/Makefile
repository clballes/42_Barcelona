# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 13:28:06 by clballes          #+#    #+#              #
#    Updated: 2023/01/09 15:20:26 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

# Path
LIBFT_DIR = LIBFT/
LIBFT = ${LIBFT_DIR}/libft.a

PRINTF_DIR = PRINTF/
PRINTF = ${PRINTF_DIR}/libftprintf.a
INC_DIR = inc/

LIB = ${INC_DIR}/push_swap.h
SRCS_DIR = src/

# Sources
SRCS = $(SRCS_DIR)ft_check.c $(SRCS_DIR)ft_funciones_list.c $(SRCS_DIR)ft_push_swap.c $(SRCS_DIR)ft_utils_list.c $(SRCS_DIR)ft_operaciones.c $(SRCS_DIR)ft_sort_short.c $(SRCS_DIR)ft_op_sort_b.c $(SRCS_DIR)ft_sortlong.c $(SRCS_DIR)ft_sortb.c $(SRCS_DIR)ft_sort5hundred.c

DEPS = $(SRCS:%.c=%.d)
OBJ = $(SRCS:%.c=%.o)

$(NAME): $(OBJ) $(LIB) $(LIBFT) $(PRINTF) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\n🤠💫 You are ready to sort lists 🤠💫\n"

# gcc -flags _i incs -LPRINTF_DIR -LIBFT_DIR -lftprintf -lft
$(LIBFT): 
		@make -sC $(LIBFT_DIR)

$(PRINTF): 
		@make -sC $(PRINTF_DIR)

%.o: %.c
	@echo "Compiling...[$<]"
	@$(CC) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/INC -c $(CFLAGS) -MMD $< -o $@

clean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(PRINTF_DIR)
	@echo "\n🌼 It is all safe and clean 🌼\n"

fclean: clean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re