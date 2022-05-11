GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		= libft.a

#Paths
INCLUDE		= ./include/
OBJ_PATH	= ./obj/
SRC_PATH	= ./src/

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror

MKDIR		= mkdir -p
REMOVE 		= rm -f

SRC_FILES 	= 	ft_isalpha.c 		\
				ft_isdigit.c 		\
				ft_isalnum.c 		\
				ft_isascii.c 		\
				ft_isprint.c 		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_memset.c 		\
				ft_bzero.c 			\
				ft_memcpy.c 		\
				ft_memmove.c 		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strdup.c 		\
				ft_calloc.c 		\
				ft_putchar_fd.c 	\
				ft_putstr_fd.c 		\
				ft_putendl_fd.c 	\
				ft_putnbr_fd.c		\
				ft_striteri.c 		\
				ft_strlcpy.c 		\
				ft_strlen.c 		\
				ft_strlcat.c 		\
				ft_toupper.c 		\
				ft_tolower.c 		\
				ft_strchr.c 		\
				ft_strrchr.c 		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_atoi.c 			\
				ft_strnstr.c 		\
				ft_itoa.c 			\
				ft_substr.c	 		\
				ft_split.c 			\
				ft_strjoin.c 		\
				ft_strtrim.c		\
				ft_itoa.c 			\
				ft_strmapi.c 		\

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: init $(NAME)

init:
	@$(MKDIR) $(SRC_PATH) $(OBJ_PATH)

$(NAME): 	$(OBJ)
		@echo "\n$(NAME): $(GREEN)$(NAME) was created$(RESET)"
		@ar -rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(INCLUDE)*.h
		@${CC} ${FLAGS} -I $(INCLUDE) -c $< -o $@
		
clean:
		@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
		@$(REMOVE) $(OBJ)
		@echo

fclean:		clean
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
		@$(REMOVE) $(NAME)
		@echo

re :		fclean all

.PHONY:		all clean fclean re