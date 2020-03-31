##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GAME_ONE		=	game_nibbler/
GAME_TWO		=	game_pacman/
GAME_THREE		=	game_centiped/


all:
	make -C	$(GAME_ONE)
	make -C	$(GAME_TWO)
	make -C	$(GAME_THREE)

clean:
	make -C	$(GAME_ONE)
	make -C	$(GAME_TWO)
	make -C	$(GAME_THREE)

fclean:
	make -C	$(GAME_ONE)
	make -C	$(GAME_TWO)
	make -C	$(GAME_THREE)
	rm -f lib_arcade_nibbler.so lib_arcade_pacman.so lib_arcade_centiped.so

re:
	make -C	$(GAME_ONE) re
	make -C	$(GAME_TWO) re
	make -C	$(GAME_THREE) re


.PHONY: all clean fclean re