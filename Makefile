# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 03:41:23 by aball             #+#    #+#              #
#    Updated: 2022/03/21 16:50:15 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

UNAME = ${shell uname}

SRCS = srcs/make_map.c srcs/check_map_edge.c srcs/check_map.c srcs/read_map.c \
	srcs/map_init.c srcs/my_strjoin.c srcs/so_long_utils.c \
	srcs/get_next_line.c srcs/get_next_line_utils.c srcs/delete.c

OBJS = ${SRCS:c=o}

CFLAGS = -Wall -Wextra -Werror

ifeq ($(UNAME), Darwin)
LINKS = -framework OpenGL -framework Appkit -L /Users/aball/Desktop/minilibx_opengl -lmlx

LIBDIR = ../minilibx_opengl
endif

ifeq ($(UNAME), Linux)
LINKS = -Lminilibx_linux -lmlx -lXext -lX11

LIBDIR = ../minilibx_linux
endif

CC = gcc

INC = srcs/so_long.h

%.o: %.c ${INC} libft mlx
	${CC} -g -I libft ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} ${SRCS} srcs/main.c ${LINKS} libft/libft.a -o ${NAME}

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