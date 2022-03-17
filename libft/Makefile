# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 14:07:38 by aball             #+#    #+#              #
#    Updated: 2022/03/02 23:05:39 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_isprint.c ft_substr.c ft_atoi.c \
	ft_tolower.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memchr.c ft_isalnum.c \
	ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c \
	ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_strtrim.c ft_bzero.c \
	ft_strlcpy.c ft_strlcat.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

INCLUDES = libft.h

OBJS = ${SRCS:c=o}

OBJSBONUS = ${BONUS:c=o}

CC		= gcc
RM		= rm -f

FLAGS = -Wall -Wextra -Werror

GREEN:=\033[1;32m
RED:=\033[1;31m
BLUE:=\033[1;34m
END:=\033[0m

%.o: %.c $(INCLUDES) printf
		@${CC} -g ${FLAGS} -c $< -o ${<:c=o}
		@echo "⏳ ${BLUE}Compiling libft...${END}"

$(NAME):	${OBJS}
		@ar crs ${NAME} ${OBJS}

bonus: ${OBJSBONUS}
		@ar crs ${NAME} ${OBJSBONUS}
		@echo "⏳ ${BLUE}Compiling bonus...${END}"

all:	${NAME}

printf:
		make -C printf
		cp printf/libftprintf.a libft.a

clean:
		@make clean -C printf
		@${RM} ${OBJS} ${OBJSBONUS}
		@echo "🧹 ${RED}Removing object files...${END} 🧹"

fclean:	clean
		@make fclean -C printf
		@${RM} ${NAME}
		@echo "🧹 ${RED}Removing library...${END} 🧹"

re:		fclean all
		@echo "${GREEN}Done ✅${END}"

.PHONY: fclean all re bonus clean printf