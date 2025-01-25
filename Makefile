CC = gcc
CFLAGS = -g -Wall
SRCS = push_swap.c \
       algorithm_sort.c \
       algorithm_utils.c \
       algorithm_utils2.c \
       algorithm_utils3.c \
	   algorithm_utils4.c \
       argument_check_utils.c \
       stack_operations.c \
       stack_utils.c \
       stack_utils2.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
TARGET = push_swap

all:	$(LIBFT) $(TARGET)

$(LIBFT):
	$(MAKE)	-C $(LIBFT_DIR)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS) $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re