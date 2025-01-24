CC = gcc
CFLAGS = -g -Wall
SRCS = push_swap.c algorithm_sort.c algorithm_utils.c algorithm_utils2.c algorithm_utils3.c argument_check_utils.c stack_operations.c stack_utils.c stack_utils2.c
OBJS = $(SRCS:.c=.o)
TARGET = push_swap

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean