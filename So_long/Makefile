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
# OLD_MAKE = /usr/bin/make3.81

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
LIB_BONUS = ${INC_DIR}/so_long_bonus.h
LIB_GET = ${INC_DIR}/get_next_line.h
MLX_DIR = mlx/
MLX = ${MLX_DIR}libmlx.a
MINILIBXCC	=  -L $(MLX_DIR) -lmlx
OPENGL = -framework OpenGL -framework AppKit

SRCS = $(SRCS_DIR)map_err.c $(SRCS_DIR)so_long.c $(SRCS_DIR)so_long_utils.c $(SRCS_DIR)create_map.c $(GET_DIR)get_next_line_utils.c $(GET_DIR)get_next_line.c  $(SRCS_DIR)valid_path.c $(SRCS_DIR)moves.c $(SRCS_DIR)map_func.c

BONUS =$(BONUS_DIR)map_err_bonus.c $(BONUS_DIR)so_long_bonus.c $(BONUS_DIR)so_long_utils_bonus.c $(BONUS_DIR)create_map_bonus.c $(GET_DIR_BONUS)get_next_line_utils_bonus.c $(GET_DIR_BONUS)get_next_line_bonus.c  $(BONUS_DIR)valid_path_bonus.c $(BONUS_DIR)moves_bonus.c $(BONUS_DIR)printmap_bonus.c $(BONUS_DIR)init_bonus.c 

OBJ = $(SRCS:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
DEPS_BONUS = $(BONUS:%.c=%.d)

# Gcc
$(NAME): $(OBJ) $(LIB) $(MLX) $(LIBFT) $(LIB_GET)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR)  $(OBJ) $(MINILIBXCC) $(LINK) $(OPENGL) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB_BONUS) $(MLX) $(LIBFT) $(LIB_GET) 
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(BONUS_OBJ) $(MINILIBXCC) $(LINK) $(OPENGL) -o $(BONUS_NAME)

$(LIBFT): 
		@MAKE -sC $(LIBFT_DIR)
$(MLX): 
		@MAKE -sC $(MLX_DIR)

%.o: %.c Makefile
	echo "Compiling...[$<]"
	$(CC) -I$(INC_DIR) -I mlx -I$(LIBFT_DIR) -c $(CFLAGS)  $< -o $@

clean:
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) $(OBJ) ${BONUS_OBJ}
	rm -rf ${DEPS} ${DEPS_BONUS}
	MAKE clean -sC $(LIBFT_DIR)
	MAKE clean -sC $(MLX_DIR)
	echo "\n🌼 It is all safe and clean 🌼\n"

fclean: clean
	 MAKE fclean -sC $(LIBFT_DIR)
	 MAKE fclean -sC $(MLX_DIR)

re: fclean all

all: $(NAME) $(BONUS_NAME)

-include ${DEPS} ${DEPS_BONUS}

.PHONY: all clean fclean re bonus