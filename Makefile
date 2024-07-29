# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 00:12:48 by akamite           #+#    #+#              #
#    Updated: 2024/07/29 20:01:06 by akamite          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CFLAGS	= -Wall -Werror -Wextra

# minilibX
MLX_DIR 		= minilibx-linux
MLX_A				= $(MLX_DIR)/libmlx.a

MLX_INCS		= \
	-I/opt/homebrew/Cellar/libx11/1.8.9/include -I/opt/homebrew/Cellar/libxcb/1.17.0/include -I/opt/homebrew/Cellar/libxau/1.0.11/include -I/opt/homebrew/Cellar/libxdmcp/1.1.5/include -I/opt/homebrew/Cellar/xorgproto/2024.1/include \
	-I $(MLX_DIR) 

MLX_LIBS		= \
	-L /opt/homebrew/Cellar/libx11/1.8.9/lib \
	-L /opt/homebrew/opt/libxext/lib \
	-L $(MLX_DIR) \
	-lmlx -lXext -lX11 -lm -lz


SRC_DIR	= src/
OBJ_DIR	= obj/

SRC	= \
	main.c

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INCS	= -I ./includes/ $(MLX_INCS)


all: $(MLX_A) $(NAME)

$(MLX_A):
	make -sC $(MLX_DIR)/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(MLX_LIBS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	make -C $(MLX_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
