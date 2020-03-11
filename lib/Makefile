##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

LIB_ONE		=	lib_one/
LIB_TWO		=	lib_two/
LIB_THREE	=	lib_three/


all:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	make -C	$(LIB_THREE)

clean:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	make -C	$(LIB_THREE)

fclean:
	make -C	$(LIB_ONE)
	make -C	$(LIB_TWO)
	make -C	$(LIB_THREE)
	rm -f lib_one.so lib_two.so lib_three.so

re:
	make -C	$(LIB_ONE) re
	make -C	$(LIB_TWO) re
	make -C	$(LIB_THREE) re


.PHONY: all clean fclean re