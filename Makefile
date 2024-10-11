# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbourre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 17:15:32 by cbourre           #+#    #+#              #
#    Updated: 2023/02/14 13:58:21 by cbourre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### FILES #####################################################################

NAME = so_long

SRC = ext_checker.c \
		ft_free.c \
		ft_sprites.c \
		ft_wasd.c \
		map_check_path.c \
		map_parsing.c \
		message_error.c \
		read_map.c \
		so_long.c
SRCS = $(addprefix srcs/, $(SRC))

OBJS = $(SRCS:.c=.o)

########## LIBFT

LIB_DIR =	libft

LIB_NAME =	libft/libft.a

########## MINILIBX

MLX_DIR =	mlx_linux/

MLX_NAME =	mlx_linux/libmlx_Linux.a


#### COMPIL ####################################################################

CC =		clang

CFLAGS =	-Wall -Wextra -Werror -I. -g

MLXFLAGS =	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM =		rm -rf


#### RULES #####################################################################

all: $(NAME)

%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME):
	make -sC $(LIB_DIR)

$(MLX_NAME):
	make -sC $(MLX_DIR)

$(NAME): $(OBJS) $(LIB_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_NAME) $(MLX_NAME) $(MLXFLAGS)


#### BIN #######################################################################

clean:
	$(RM) $(OBJS)
	make -sC $(LIB_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -sC $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
