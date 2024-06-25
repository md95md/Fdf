NAME = fdf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c get_map.c draw.c draw.c errors.c free.c

OBJ = $(SRC:.c=.o)

HEADER = fdf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re