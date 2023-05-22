##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile
##

SRC		=	src/main.c		\
			src/solver.c	\
			src/move.c		\
			src/stop.c

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

TEST	=	unit_test

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LIB	=	-L../lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

debug: CFLAGS+=-g3
debug: re

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST)

re:	fclean all

.PHONY: all debug clean fclean re
