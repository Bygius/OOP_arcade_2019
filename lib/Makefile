##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

LIB_ONE		=	lib_sfml/
LIB_TWO		=	lib_ncurses/
LIB_THREE	=	lib_three/


all:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	# make -C	$(LIB_THREE)

clean:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	# make -C	$(LIB_THREE)

fclean:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	# make -C	$(LIB_THREE)
	rm -f lib_arcade_sfml.so lib_arcade_ncurses.so lib_three.so

re:
	make -C	$(LIB_ONE) re
	make -C	$(LIB_TWO) re
	# make -C	$(LIB_THREE) re


.PHONY: all clean fclean re