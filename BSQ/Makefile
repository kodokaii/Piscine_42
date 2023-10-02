CC = gcc
CFLAGS += -Wall -Wextra -Werror
EXEC = bsq
SRC = $(wildcard ./srcs/*.c)
OBJ = $(SRC:.c=.o)
PATH_HEAD = ./includes/

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(PATH_HEAD) -c $< -o $@

newMap:
	perl gen.perl 40 20 8 > map$$(echo $$(ls map* | tail -c2) + 1 | bc)

rmMap:
	rm -f map*

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: clean fclean re all newMap rmMap
