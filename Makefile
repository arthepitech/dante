##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile
##

all:
	make -C lib/my
	make -C generator
	make -C solver

debug:
		make -C lib/my
		make debug -C generator
		make debug -C solver

clean:
	make clean -C lib/my
	make clean -C generator
	make clean -C solver

fclean:
	make fclean -C lib/my
	make fclean -C generator
	make fclean -C solver

re:	fclean all

.PHONY: all debug clean fclean re
