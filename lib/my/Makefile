##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_strlen.c \
		my_getnbr.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_is_prime.c \
		my_find_prime_sup.c \
		my_strcpy.c \
		my_strncpy.c \
		my_revstr.c \
		my_strstr.c \
		my_nbr_to_str.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strupcase.c \
		my_strlowcase.c \
		my_strcapitalize.c \
		my_str_isalpha.c \
		my_str_isnum.c \
		my_str_islower.c \
		my_str_isupper.c \
		my_str_isprintable.c \
		my_strcat.c \
		my_strncat.c \
		my_strmcat.c \
		my_str_to_word_array.c	\
		my_str_to_word_arr.c \
		my_strmcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

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
