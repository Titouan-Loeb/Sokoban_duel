##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	msf_anim.c					\
		msf_create_image.c			\
		msf_create_text.c			\
		msf_get_time.c				\
		msf_is_on_sprite.c			\
		msf_move_sprite.c			\
		msf_range.c					\
		msf_set_sound.c             \
		msf_sprite_orientation.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libsfml.a

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
