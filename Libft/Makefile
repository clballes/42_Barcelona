# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:57:29 by clballes          #+#    #+#              #
#    Updated: 2022/06/17 16:23:16 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_strlcat.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_itoa.c

BONUS = ft_lstmap.c ft_lstiter.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstdelone.c ft_lstclear.c $(SRCS)

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)

LIB = libft.h

#Comandoos

%.o : %.c
	${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

${NAME} : ${OBJS} ${LIB}
#	${CC} ${OBJS} libft.a -o ${NAME}
	@ar -rcs ${NAME} ${OBJS}
	@ranlib ${NAME}
	
bonus: $(OBJS_BONUS)
	 @ar -rcs ${NAME} ${OBJS_BONUS}
clean:
	rm -rf ${OBJS}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean
	$(MAKE)	

.PHONY: fclean, all, clean, re
