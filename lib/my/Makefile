##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

SRC	=	my_strlen.c			\
		my_strcmp.c			\
		file_size.c			\
		free_all.c			\
		my_str_to_word_array.c	\
		my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
