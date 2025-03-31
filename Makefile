NAME = so_long
CC = cc
CFLAGS = -Wextra -Wall -Werror -Iinclude -Imlx_linux -I/usr/include -g
MLX_FLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lm -lpthread 
LIBFT = libft/libft.a
HEADER_DIR = include
HEADER = $(HEADER_DIR)/so_long.h
MLX = mlx_linux/libmlx.a
SRC_DIR = src

SRC = $(SRC_DIR)/so_long.c\
	$(SRC_DIR)/parsing.c\
	$(SRC_DIR)/parsing_2.c\
	$(SRC_DIR)/free_and_errors.c\
	$(SRC_DIR)/input.c\
	$(SRC_DIR)/flood_fill.c

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ) Makefile $(HEADER)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) successfully created! 🎉"

$(LIBFT): force
	@make -C libft 

$(MLX):
	@make -C mlx_linux  >/dev/null 2>&1

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@make -C libft clean --silent
	@make -C mlx_linux clean >/dev/null 2>&1

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@make -C libft fclean --silent

force: 

re: fclean all 

.PHONY: all clean fclean force re