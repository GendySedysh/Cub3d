INC=./includes

INCLIB=mlx_linux

CC=gcc

CFLAGS= -I$(INC) -g -O3 -Wall -Wextra -Werror

NAME= cub3D

SRC = 	utils/from_libft.c \
		utils/from_libft_2.c \
		utils/gnl.c \
		utils/gnl_utils.c \
		utils/save.c \
		utils/sprite_list.c \
		utils/ini_func.c \
		utils/ini_func_2.c \
		utils/trash.c \
		map_parcer/map_check.c \
		map_scale/map_data_sprites.c \
		game/player.c \
		game/render.c \
		game/render_textures.c \
		game/render_screenshot.c \
		game/render_utils.c \
		game/keys.c \
		game/move.c \
		game/textures.c \
		map_parcer/map_parcer_utils.c \
		map_parcer/map_parcer.c \
		map_valid/map_valid.c \
		map_valid/exit_func.c \
		map_valid/input_data.c \
		main.c \
		map_scale/map_scale.c 

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(MAKE) -C ./mlx_linux
	$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	rm -f ./game/*.o
	rm -f ./map_parcer/*.o
	rm -f ./map_scale/*.o
	rm -f ./mlx_linux/*.o
	rm -f ./list_utils/*.o
	rm -f ./map_valid/*.o
	rm -f ./utils/*.o
	rm -f ./*.o

fclean	: clean
	rm -f ./mlx_linux/*.a
	rm -f cub3D
	rm -f ./*.bmp

re	: clean all