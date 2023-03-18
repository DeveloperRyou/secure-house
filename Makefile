NAME = secure_house
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c \
		init.c \
		utils.c \
		print.c \
		operate.c \
		free.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
