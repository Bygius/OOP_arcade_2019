##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC_DIR		=	./src/

INC_DIR		=	./include/

RM			=	rm -f

CC			=	g++

SRC			=	$(SRC_DIR)main.cpp		\
				$(SRC_DIR)Core.cpp			

OBJ			=	$(SRC:.cpp=.o)

CFLAGS  	+=	-Wall -Wextra

NAME		=	arcade

all: 			$(NAME)
				cp $(NAME) ../

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ)

clean:
				$(RM) -f $(OBJ)

fclean: 		clean
				$(RM) -f $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re