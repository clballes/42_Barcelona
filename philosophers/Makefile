NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = /bin/rm -f

# Path
INC_DIR = inc/
SRCS_DIR = src/

# Sources
LIB = ${INC_DIR}/philosophers.h
SRCS = $(SRCS_DIR)main.c $(SRCS_DIR)philo_utils.c $(SRCS_DIR)functions.c $(SRCS_DIR)init.c

DEPS = $(SRCS:%.c=%.d)
OBJ = $(SRCS:%.c=%.o)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n💫 You are ready to start philosopers 💫\n"

%.o: %.c
	echo "Compiling...[$<]"
	$(CC) -I$(INC_DIR) -c $(CFLAGS) -MMD $< -o $@

clean:
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	echo "\n🌼 It is all safe and clean 🌼\n"

fclean: clean

re: fclean all

all: $(NAME)

-include ${DEPS}

.PHONY: all clean fclean re

# 4 410 200 200