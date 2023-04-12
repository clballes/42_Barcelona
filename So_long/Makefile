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
BONUS_NAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = /bin/rm -rf

# Path
LIBFT_DIR = ./libft/
LIBFT = ${LIBFT_DIR}libft.a
LINK = -L$(LIBFT_DIR) -lft
SRCS_DIR = srcs/
BONUS_DIR = bonus/
GET_DIR = srcs/get_next_line/
GET_DIR_BONUS = bonus/get_next_line/
INC_DIR = inc/
LIB = ${INC_DIR}/so_long.h
LIB_GET = ${INC_DIR}/get_next_line.h
MLX_DIR = mlx/
MLX = ${MLX_DIR}libmlx.a
MINILIBXCC	= -I mlx -L $(MLX_DIR) -lmlx
OPENGL = -framework OpenGL -framework AppKit

SRCS = $(SRCS_DIR)map_err.c $(SRCS_DIR)so_long.c $(SRCS_DIR)so_long_utils.c $(SRCS_DIR)create_map.c $(GET_DIR)get_next_line_utils.c $(GET_DIR)get_next_line.c  $(SRCS_DIR)valid_path.c $(SRCS_DIR)moves.c $(SRCS_DIR)printmap.c

BONUS =$(BONUS_DIR)map_err_bns.c $(BONUS_DIR)so_long_bns.c $(BONUS_DIR)so_long_utils_bns.c $(BONUS_DIR)create_map_bns.c $(GET_DIR_BONUS)get_next_line_utils_bns.c $(GET_DIR_BONUS)get_next_line_bns.c  $(BONUS_DIR)valid_path_bns.c $(BONUS_DIR)moves_bns.c $(BONUS_DIR)printmap_bns.c $(BONUS_DIR)init_bns.c 

OBJ = $(SRCS:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
DEPS_BONUS = $(BONUS:%.c=%.d)

# Gcc
$(NAME): $(OBJ) $(LIB) $(MLX) $(LIBFT) $(LIB_GET)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(LINK) $(OBJ) $(MINILIBXCC) $(OPENGL) -o $(NAME)

bonus: $(BONUS_OBJ) $(LIB) $(MLX) $(LIBFT) $(LIB_GET) 
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(BONUS_OBJ) $(MINILIBXCC) $(LINK) $(OPENGL) -o $(BONUS_NAME)

$(LIBFT): 
		@make -sC $(LIBFT_DIR)
$(MLX): 
		@make -sC $(MLX_DIR)

%.o: %.c
	echo "Compiling...[$<]"
	$(CC) -I$(INC_DIR) -I$(LIBFT_DIR) -c $(CFLAGS)  $< -o $@

clean:
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) $(OBJ) ${BONUS_OBJ}
	rm -rf ${DEPS} ${DEPS_BONUS}
	make clean -sC $(LIBFT_DIR)
	make clean -sC $(MLX_DIR)
	echo "\n🌼 It is all safe and clean 🌼\n"

fclean: clean
	 make fclean -sC $(LIBFT_DIR)
	 make fclean -sC $(MLX_DIR)

re: fclean all

all: $(NAME)

-include ${DEPS} ${DEPS_BONUS}

.PHONY: all clean fclean re