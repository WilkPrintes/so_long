NAME = so_long

CC		:=	gcc

#gcc *.c ./gnl/*.c -I ./libraries/minilibx/ -L ./libraries/minilibx/ -lmlx -Ilmlx -lXext -lX11 ./libraries/minilibx/libmlx.a

HEADER_DIR	:=	./ ./libraries/minilibx/ ./gnl

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I$(directory))

SRC_DIR		:=	./

SRC_FILE	:=	controlers.c maps.c render_map.c so_long.c \
				ft_strncmp.c ft_strnstr.c
				

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

GNL_FILE	:=	get_next_line.c get_next_line_utils.c

GNL_DIR		:=	./gnl/

GNL			:=	$(foreach file, $(GNL_FILE), $(GNL_DIR)$(file))

LIBS_DIR	:=	./libraries/minilibx/

LIBS		:=	-L $(LIBS_DIR) -lmlx -Ilmlx -lXext -lX11 $(LIBS_DIR)libmlx.a

all: $(NAME)

$(NAME):
	$(CC) -g $(SRC) $(GNL) -o $@ $(INCLUDE) $(LIBS) 

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean:
	rm -rf $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@