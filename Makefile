NAME = so_long

SRCS = srcs/main.c srcs/map.c srcs/events.c srcs/errors.c srcs/check_path.c srcs/map_copy.c srcs/free.c srcs/textures.c
OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror -g3
C_FLAGS = -Llibft -lft -Lminilibx -lmlx_Linux -lX11 -lXext -lm -lz -Iincludes

LIBFT = libft.a
LIBPATH = libft

MLX = libmlx.a
MLXPATH = minilibx

# .c.o:
# 	${CC} ${C_FLAGS} -I${HEADER} -c $< -o $@

all : $(NAME)


$(NAME) :
	@make -s re -C ${LIBPATH}
	@make -s re -C ${MLXPATH}
	${CC} ${SRCS} ${C_FLAGS} ${LIBPATH}/${LIBFT} ${MLXPATH}/${MLX} -o ${NAME}
	@echo "\033[32mSo_long Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
	rm -rf ${OBJS}
	@make clean -C libft
	@make clean -C minilibx

fclean: clean
	rm -rf ${NAME}
	@make fclean -C libft
	@make -C minilibx clean
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

.PHONY: all libft clean fclean re
