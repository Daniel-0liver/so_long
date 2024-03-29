GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm
#-lmlx -framework OpenGL -framework AppKit
#valgrind --leak-check=full --show-leak-kinds=all
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c \
				src/game_hook_events.c \
				src/game_init_events.c \
				src/game_close_events.c \
				src/game_render_events.c \
				src/player_events.c \
				src/map_valid_events.c \
				src/input_valid_events.c

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ $(GREEN)OK$(RESET) ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ $(GREEN)OK$(RESET) ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			@echo "$@ $(GREEN)created$(RESET)"
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "Object files removed."

fclean:		clean
			@make -s $@ -C libft
			#@make -s $< -C mlx
			@rm -rf $(NAME)
			@echo "Binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
