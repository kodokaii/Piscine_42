CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a
SRC = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJ = $(SRC:.c=.o)
PATH_HEAD = ./includes/

all: $(LIB)

$(LIB): $(OBJ)
	ar -r $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(PATH_HEAD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all
