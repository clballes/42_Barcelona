# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 14:55:16 by clballes          #+#    #+#              #
#    Updated: 2023/02/23 14:55:42 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

# Path
LIBFT_DIR = LIBFT/
LIBFT = ${LIBFT_DIR}/libft.a
SRCS_DIR = srcs/
INC_DIR = inc/
LIB = ${INC_DIR}/so_long.h

#Objects & dependencies falten dependencies !!

SRCS = $(SRCS_DIR)so_long.c $(SRCS_DIR)map_errors.c

OBJ = $(SRCS:%.c=%.o)

# Gcc

$(NAME): $(OBJ) $(LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): 
		@make -C $(LIBFT_DIR)

%.o: %.c
	echo "Compiling...[$<]"
	$(CC) -I$(INC_DIR) -I$(LIBFT_DIR) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(NAME)
	$(RM) $(OBJ)
	make clean -sC $(LIBFT_DIR)
	echo "\n🌼 It is all safe and clean 🌼\n"

fclean: clean
	 make fclean -sC $(LIBFT_DIR)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
