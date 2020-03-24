##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

DIR_GAME	=	games/
DIR_LIB		=	lib/
DIR_CORE	=	core/
DIR_DOC 	= 	doc/

all:
	# make -C	$(DIR_GAME)
	make -C $(DIR_LIB)
	make -C $(DIR_CORE)

core:
	make -C	$(DIR_CORE)

games:
	make -C	$(DIR_GAME)

graphicals:
	make -C $(DIR_LIB)

clean:
	# make -C $(DIR_GAME)
	make -C $(DIR_LIB)
	make -C $(DIR_CORE)

fclean:
	make -C $(DIR_DOC) fclean
	# make -C $(DIR_GAME) fclean
	make -C $(DIR_LIB) fclean
	make -C $(DIR_CORE) fclean

re:
	# make -C $(DIR_GAME) re
	make -C $(DIR_LIB) re
	make -C $(DIR_CORE) re

doc:
	make -C $(DIR_DOC)

.PHONY: all clean fclean re core games lib doc