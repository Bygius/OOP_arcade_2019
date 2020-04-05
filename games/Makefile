##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GAME_ONE		=	game_nibbler/
GAME_TWO		=	game_pacman/


all:
	make -C	$(GAME_ONE)
	make -C	$(GAME_TWO)

clean:
	make -C	$(GAME_ONE) clean
	make -C	$(GAME_TWO) clean

fclean:
	make -C	$(GAME_ONE) fclean
	make -C	$(GAME_TWO) fclean
	rm -f lib_arcade_nibbler.so lib_arcade_pacman.so

re:
	make -C	$(GAME_ONE) re
	make -C	$(GAME_TWO) re


.PHONY: all clean fclean re