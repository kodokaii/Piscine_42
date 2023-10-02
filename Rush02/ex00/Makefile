CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = rush-02
SRC = $(wildcard ./srcs/*.c)
OBJ = $(SRC:.c=.o)
PATH_HEAD = ./includes/

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(PATH_HEAD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
