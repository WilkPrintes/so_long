NAME = so_long

CC		:=	gcc

#gcc *.c ./gnl/*.c -I ./libraries/minilibx/ -L ./libraries/minilibx/ -lmlx -Ilmlx -lXext -lX11 ./libraries/minilibx/libmlx.a

LIBFT = libraries/libft/libft.a
LIBFT_PATH = libraries/libft
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

HEADER_DIR	:=	./ ./libraries/minilibx/ ./get_next_line ./libraries/libft

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:=	./

SRC_FILE	:=	controlers.c maps.c render_map.c so_long.c
				
SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

GNL_FILE	:=	get_next_line.c get_next_line_utils.c

GNL_DIR		:=	./get_next_line/

GNL			:=	$(foreach file, $(GNL_FILE), $(GNL_DIR)$(file))

MLX_DIR	:=	./libraries/minilibx/

MLX			:= $(MLX_DIR)libmlx.a

LIBS		:=	-L $(MLX_DIR) -lmlx -Ilmlx -lXext -lX11 $(MLX)

all: $(NAME) 

$(NAME): $(LIBFT) $(MLX) $(SRC)
	$(CC) -g $(SRC) $(GNL) -o $@ $(INCLUDE) $(LIBS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean fclean re