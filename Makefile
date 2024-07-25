NAME = fdf
CC = gcc
LIBFT_DIR = ../libft
GNL_DIR = ../get_next_line
MLX_HDIR = ../MLX42/include/MLX42
CFLAGS = -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_HDIR) -g -O0
LFLAGS = -Wall -Wextra -Werror -ldl -lglfw -pthread -lm
LDFLAGS = -Llibft
LIBS = $(LIBFT_DIR)/libft.a ../MLX42/build/libmlx42.a
SRC = draw_map.c shift.c rotate.c hooks.c draw_line.c main.c read_map.c get_map.c \
	../get_next_line/get_next_line.c \
	../get_next_line/get_next_line_utils.c \

OBJ = $(SRC:%.c=%.o)
HEADER = fdf.h $(LIBFT_DIR)/libft.h $(GNL_DIR)/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LFLAGS) $(LDFLAGS) -o $(NAME) -fsanitize=address,undefined -g3

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
