##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile that compile the lib
##

SRC	=	src/init/main.c						\
		src/init/read_map.c					\
		src/init/init_graphics.c			\
		src/init/init_game.c				\
		src/screens/main_menu.c				\
		src/screens/level_selection.c		\
		src/screens/solo_game.c				\
		src/screens/duel_game.c				\
		src/main_loop.c						\
		src/error_handling/error.c			\
		src/game/highlight_crate.c			\
		src/game/move/move_up.c				\
		src/game/move/move_down.c			\
		src/game/move/move_right.c			\
		src/game/move/move_left.c			\
		src/game/draw_game.c				\
		src/game/game_tools.c				\
		src/game/end_of_game.c

OBJ			=	$(SRC:.c=.o)

NAME		=	SOKOBAN

CC			=	gcc

CFLAGS 		=   -Wextra -Wall

LDFLAGS		=	-lmy -L ./lib/my/ -lsfml -L ./lib/sfml

LCSFML		=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm -lncurses

CPPFLAGS	+=	-I ./include

##------------------------------------------
all:    	$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my/
			make -C lib/sfml/
			$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LCSFML)

clean:
			make -C lib/my/ clean
			make -C lib/sfml/ clean
	        rm -f $(OBJ)

fclean: 	clean
			make -sC lib/my/ fclean
			make -sC lib/sfml/ fclean
	        rm -f $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re