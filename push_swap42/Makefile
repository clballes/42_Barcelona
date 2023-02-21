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

# Sources
SRCS = ft_check.c ft_funciones_list.c ft_push_swap.c ft_utils_list.c ft_operaciones.c ft_sort_short.c ft_op_sort_b.c ft_sortlong.c ft_sortb.c ft_sort5hundred.c
OBJS = $(SRCS:%.c=%.o)
LIB = push_swap.h

# Comandos
%.o: %.c
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all: $(NAME)	

libs:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)
clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $
	@$(MAKE) fclean -C $
	@$(RM) $
	
re: fclean all

.PHONY: all clean fclean re