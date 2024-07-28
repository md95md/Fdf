NAME = pipex
CC = gcc
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf_pipex
CFLAGS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
SRC = pipex.c pipex_utils.c

OBJ = $(SRC:%.c=%.o)
HEADER = pipex.h $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -g3

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re