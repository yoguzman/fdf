#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguzman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 11:38:09 by yguzman           #+#    #+#              #
#    Updated: 2016/11/25 20:08:45 by yguzman          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=		clang

NAME		=		fdf

LIBFT		=		./libft/libft.a

MLX			=		./minilibx/libmlx.a

DIR_SRC		=		./src/

SRCS		=		$(DIR_SRC)main.c					\
					$(DIR_SRC)fill_map.c				\
					$(DIR_SRC)fdf.c						\
					$(DIR_SRC)init.c					\
					$(DIR_SRC)put_line.c				\
					$(DIR_SRC)tools.c					\
					$(DIR_SRC)error.c					\

OBJS		=		$(SRCS:.c=.o)

CFLAGS		+=		-Iinclude -Iminilibx
CFLAGS		+=		-Wall -Wextra

RM			=		rm -f

LIB			=		./libft/libft.a

ECHO		=		printf

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					@make -C libft
					@make -C minilibx
					@$(ECHO) "\033[35m[~~~~COMPILATION PROJECT~~~~]\n\033[0m"
					@$(CC) -o $(NAME) -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit $(OBJS) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" || $(ECHO) "\033[31m["$@"]\n\033[0m"

%.o			:		%.c
					@$(ECHO) "\033[35m[~~~Comipilation obj //project~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m" || $(ECHO) "\033[31m ["$@"]\n\033[0m"

clean_lib	:
					@make -C libft clean
					@make -C minilibx clean

clean		:		clean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)

fclean_lib	:
					@make -C libft fclean
					@make -C minilibx fclean

fclean		:		fclean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)
					@$(ECHO) "\033[31m[~~~~Supression du Binaire~~~~]\n\033[0m"
					@$(RM) $(NAME)

re			:		fclean all

depend		:		$(SRCS)
					makedepend -- -Yinclude/ -- $^

.PHONY		:		all depend clean flean re

# DO NOT DELETE THIS LINE -- make depend depends on it.

src/main.o: include/event_key.h include/fdf.h
src/fill_map.o: include/libft.h include/fdf.h
src/fdf.o: include/fdf.h
src/init.o: include/fdf.h
src/put_line.o: include/fdf.h
src/tools.o: include/fdf.h
src/error.o: include/libft.h
