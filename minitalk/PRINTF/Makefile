# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:57:29 by clballes          #+#    #+#              #
#    Updated: 2022/10/16 18:10:36 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
INC_DIR = INC
SRCS_DIR = SRCS/
OBJ_DIR = OBJ/

SRC_FILES = ft_printf_pointer ft_printf_hexad_upp ft_printf_unsigned_decimal ft_printf_int ft_printf ft_printf_character ft_printf_string ft_printf_hexad_low ft_printf_percent ft_hexadecimal ft_printf_decimal ft_putchar

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))


#OBJS = $(SRCS:%.c=%.o)

#OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))

#LIB = ft_printf.h

#Comandos

${OBJ_DIR}%.o : ${SRCS_DIR}%.c 
	mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -MMD -I ${INC_DIR} -c $< -o $@

all: ${NAME}

-include ${DEPS}
${NAME} : ${OBJ}
	@ar -rcs ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ_DIR} ${DEPS}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean
	$(MAKE)	

.PHONY: fclean, all, clean, re
