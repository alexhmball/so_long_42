# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 03:41:23 by aball             #+#    #+#              #
#    Updated: 2022/10/19 15:20:28 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

ARC = ${shell uname}

SRCS = srcs/make_map.c srcs/check_map_edge.c srcs/check_map.c srcs/read_map.c \
	srcs/map_init.c srcs/my_strjoin.c srcs/so_long_utils.c \
	srcs/get_next_line.c srcs/get_next_line_utils.c srcs/delete.c srcs/main.c

SRCS_B = bonus/make_map_bonus.c bonus/check_map_edge_bonus.c bonus/check_map_bonus.c \
	bonus/read_map_bonus.c bonus/map_init_bonus.c bonus/my_strjoin_bonus.c \
	bonus/so_long_utils_bonus.c srcs/get_next_line.c srcs/get_next_line_utils.c \
	bonus/delete_bonus.c bonus/main_bonus.c

CFLAGS = -Wall -Wextra -Werror

ifeq (${ARC}, Darwin)
LINKS = -framework OpenGL -framework Appkit -L minilibx_opengl/ -lmlx

LIBDIR = minilibx_opengl/
endif

ifeq (${ARC}, Linux)
LINKS = -L minilibx_linux/ -lmlx -lXext -lX11 -lm -lz

LIBDIR = minilibx_linux/
endif

CC = gcc

all: ${NAME}

$(NAME): libft mlx
	${CC} ${CFLAGS} ${SRCS} libft/libft.a ${LINKS} -o ${NAME}

bonus: libft mlx
	${CC} ${CFLAGS} ${SRCS_B} ${LINKS} libft/libft.a -o ${NAME_B}

libft:
	make -C libft

mlx:
	make -C $(LIBDIR)

clean:
	make clean -C libft
	make clean -C $(LIBDIR)

fclean: clean
	make fclean -C libft
	rm -fr ${NAME} ${NAME_B} ${LIB}

re: fclean all

.PHONY: re fclean clean all bonus libft mlx
