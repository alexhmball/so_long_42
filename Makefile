# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 03:41:23 by aball             #+#    #+#              #
#    Updated: 2022/03/17 20:50:38 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/make_map.c srcs/check_map_edge.c srcs/check_map.c srcs/read_map.c \
	srcs/map_init.c srcs/my_strjoin.c srcs/so_long_utils.c \
	srcs/get_next_line.c srcs/get_next_line_utils.c srcs/delete.c

OBJS = ${SRCS:c=o}

CFLAGS = -Wall -Wextra -Werror

LINKS = -framework OpenGL -framework Appkit -L /Users/aball/Desktop/minilibx_opengl -lmlx

LIBDIR = ../minilibx_opengl

CC = gcc

INC = srcs/so_long.h

%.o: %.c ${INC} libft mlx
	${CC} -g -I libft ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} ${LINKS} libft/libft.a ${SRCS} srcs/main.c -o ${NAME}

all: ${NAME}

libft:
	@make -C libft

mlx:
	@make -C $(LIBDIR)

clean:
	@make clean -C libft
	@make clean -C $(LIBDIR)
	@rm -fr ${OBJS}

fclean: clean
	@make fclean -C libft
	@rm -fr ${NAME}

re: fclean all

.PHONY: re fclean clean all libft mlx