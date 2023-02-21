# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clballes <clballes@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 17:03:25 by clballes          #+#    #+#              #
#    Updated: 2022/10/16 18:49:23 by clballes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

# Path
LIBFT_DIR = LIBFT/
LIBFT = ${LIBFT_DIR}/libft.a
PRINTF_DIR = PRINTF/
PRINTF = ${PRINTF_DIR}/libftprintf.a
SRCS_DIR = SRCS/

# Sources
CLIENT_SRCS = ${SRCS_DIR}client.c
SERVER_SRCS = ${SRCS_DIR}server.c

OBJS_CLIENT = $(SRCS_DIR)client.o
OBJS_SERVER = ${SRCS_DIR}server.o

all:
	@Make libs
	@Make -s $(SERVER)
	@Make -s $(CLIENT)

libs: # compiling libs
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF) Makefile
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF) Makefile
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT) 

$(SRCS)%.o:$(SRCS)%.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) 
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all
bonus:
	@$(MAKE) all
.PHONY: all clean fclean re bonus
