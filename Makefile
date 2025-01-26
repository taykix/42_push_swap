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
LIBFT_DIR = ./ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
TARGET = push_swap

all: $(LIBFT) $(FT_PRINTF) $(TARGET)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT) $(FT_PRINTF)

clean:
	rm -f $(OBJS) $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re