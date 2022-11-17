# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:57:29 by clballes          #+#    #+#              #
#    Updated: 2022/06/29 17:16:26 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:%.c=%.o)


LIB = libftprint.h

#Comandos

%.o : %.c
	${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

${NAME} : ${OBJS} ${LIB}
	@ar -rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS_BONUS}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean
	$(MAKE)	

.PHONY: fclean, all, clean, re
