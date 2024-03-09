##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## go go
##

SRC 	=	src/attack.c	\
			src/struct_map_s.c	\
			src/parsing_map.c	\
			src/create_empty_map.c	\
			src/my_navy.c	\
			src/my_strcmp.c	\
			src/mini_printf.c	\
			src/util.c	\
			src/my_getnbr.c	\
			src/player1.c	\
			src/player2.c	\
			src/signal.c	\
			src/char_into_int.c	\
			src/player2_2.c	\
			src/error_handling.c	\
			src/win.c	\
			src/loose.c	\
			src/my_help.c	\
			src/good_pos.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	my_navy

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : 	fclean all
