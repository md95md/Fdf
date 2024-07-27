NAME = fdf
CC = gcc
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf_fdf
GNL_DIR = ./get_next_line_fdf
MLX_HDIR = ./MLX42_fdf/include/MLX42
MLX_DIR = ./MLX42_fdf
MLX = ./MLX42_fdf/build/libmlx42.a
CFLAGS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_HDIR) -Iinclude -g -O0
LFLAGS = -Wall -Wextra -Werror -ldl -lglfw -pthread -lm
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR)
SRC = ./src/draw_map.c \
		./src/shift.c \
		./src/rotate.c \
		./src/hooks.c \
		./src/draw_line.c \
		./src/main.c \
		./src/read_map.c \
		./src/get_map.c \
		./get_next_line_fdf/get_next_line.c \
		./get_next_line_fdf/get_next_line_utils.c \
		./ft_printf_fdf/ft_printf.c \
		./ft_printf_fdf/ft_put.c \
		./ft_printf_fdf/ft_print.c \

OBJ = $(SRC:%.c=%.o)
HEADER = ./src/fdf.h $(MLX_HDIR)/MLX42.h $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h $(GNL_DIR)/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a 
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -g3

$(MLX):
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(MLX_DIR)/build
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
