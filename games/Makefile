##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GAME_ONE		=	game_one/
GAME_TWO		=	game_two/
GAME_THREE		=	game_three/


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
	rm -f game_one.so game_two.so game_three.so

re:
	make -C	$(GAME_ONE) re
	make -C	$(GAME_TWO) re
	make -C	$(GAME_THREE) re


.PHONY: all clean fclean re