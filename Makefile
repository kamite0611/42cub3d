# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 00:12:48 by akamite           #+#    #+#              #
#    Updated: 2024/08/12 17:34:31 by mnakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address

# minilibX
MLX_DIR 		= minilibx-linux
MLX_A				= $(MLX_DIR)/libmlx.a

#modified
X11_PREFIX = $(shell brew --prefix libx11)
XCB_PREFIX = $(shell brew --prefix libxcb)

MLX_INCS = \
	-I$(X11_PREFIX)/include -I$(XCB_PREFIX)/include -I$(shell brew --prefix libxau)/include -I$(shell brew --prefix libxdmcp)/include -I$(shell brew --prefix xorgproto)/include \
	-I $(MLX_DIR)

MLX_LIBS = \
	-L$(X11_PREFIX)/lib \
	-L $(shell brew --prefix libxext)/lib \
	-L $(MLX_DIR) \
	-lmlx -lXext -lX11 -lm -lz

# libft
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a


SRC_DIR	= src/
OBJ_DIR	= obj/

SRC	= \
	actions/key_handler.c \
	actions/move.c \
	actions/rotate.c \
	init/init_player.c \
	init/init_mapinfo.c \
	init/init_img.c \
	init/init_game.c \
	init/init_ray.c \
	init/init_tex_ray.c \
	init/init_texture.c \
	exit/free_exit.c \
	map_check/args_checker.c \
	render/raycasting.c \
	render/render_utils.c \
	render/render.c \
	texture/floor_ceiling.c \
	texture/wall.c \
	utils/error.c \
	utils/debug.c \
	utils/free.c \
	main.c

A_FILES	= $(LIBFT_A)
SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INCS	= \
	-I ./includes/ \
	-I ./libft/ \
	$(MLX_INCS)



all: dirs buildLibs $(NAME)

dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/actions
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/exit
	@mkdir -p $(OBJ_DIR)/map_check
	@mkdir -p $(OBJ_DIR)/render
	@mkdir -p $(OBJ_DIR)/texture
	@mkdir -p $(OBJ_DIR)/utils

buildLibs:
	make -C $(MLX_DIR)/
	make -C $(LIBFT_DIR)/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(A_FILES) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# clean:
# 	make -C $(MLX_DIR) clean
# 	make -C $(LIBFT_DIR) clean
# 	$(RM) -r $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: re
	./$(NAME) maps/good_map1.cub

test_map: re
	sh test_map.sh
