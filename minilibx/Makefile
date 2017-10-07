CC			=		cc

NOM			=		libmlx.a

SRC			=		mlx_shaders.c				\
					mlx_new_window.c			\
					mlx_init_loop.m				\
					mlx_new_image.m				\
					mlx_xpm.c					\
					mlx_int_str_to_wordtab.c

OBJ1		=		$(SRC:.c=.o)

OBJ			=		$(OBJ1:.m=.o)

CFLAGS		+=		-O2 -I../include/

ECHO		=		printf

all			:		$(NOM)

$(NOM)		:		$(OBJ)
					@$(ECHO) "\033[35m[~~~~COMPILATION MINILIBX~~~~]\n\033[0m"
					@ar rc $(NOM) $(OBJ) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" && ranlib $(NOM) 

%.o			:		%.c
					@$(ECHO) "\033[35m[~~~Comipilation obj //minilibx~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m"

%.o			:		%.m
					@$(ECHO) "\033[35m[~~~Comipilation obj //minilibx~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m"

clean:
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //minilibx~~~~~~]\n\033[0m"
					@rm -f $(OBJ)

fclean		:
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //minilibx~~~~~~]\n\033[0m"
					@rm -f $(OBJ)
					@$(ECHO) "\033[31m[~~~~Supression de libmlx.a~~~~]\n\033[0m"
					@rm -f $(NOM)
					@rm -f mlx_app

re: fclean all
