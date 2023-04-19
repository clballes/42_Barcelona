# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:57:29 by clballes          #+#    #+#              #
#    Updated: 2022/10/16 18:35:14 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_strlcat.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_itoa.c ft_split.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c $(SRCS)

DEPS = $(SRCS:%.c=%.d)
OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)
DEPS_BONUS = $(BONUS:%.c=%.d)

LIB = libft.h

#Comandos

%.o : %.c
	${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

bonus: $(OBJS_BONUS) 
	ar -rcs ${NAME} ${OBJS_BONUS}
	@touch $@

${NAME} : ${OBJS} ${LIB} $(OBJS_BONUS) 
	ar -rcs ${NAME} ${OBJS} $(OBJS_BONUS) 

clean:
	rm -rf ${OBJS_BONUS}
	rm -rf ${DEPS}
	rm -rf ${DEPS_BONUS}
	rm -rf bonus

fclean: clean
	rm -rf ${NAME}

re: fclean
	$(MAKE)

-include ${DEPS}

.PHONY: fclean, all, clean, re, bonus
