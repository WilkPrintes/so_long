NAME = so_long

CC		:=	gcc

LIBFT = libraries/libft/libft.a
LIBFT_PATH = libraries/libft
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

HEADER_DIR	:=	./sources/ ./get_next_line ./libraries/libft

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:=	./sources/

SRC_FILE	:=	controllers.c maps.c map_utils.c render_map.c so_long.c
				
SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

GNL_FILE	:=	get_next_line.c get_next_line_utils.c

GNL_DIR		:=	./get_next_line/

GNL			:=	$(foreach file, $(GNL_FILE), $(GNL_DIR)$(file))

FLAGS		:= -lmlx -Ilmlx -lXext -lX11

all: $(NAME) 

$(NAME): $(LIBFT) $(SRC)
	$(CC) -g $(SRC) $(GNL) -o $@ $(INCLUDE) $(LIBFT_FLAGS) $(FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean fclean re