##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC_DIR		=	./src/

INC_DIR		=	./include/

CC			=	g++

SRC			=	$(SRC_DIR)main.cpp					

OBJ			=	$(SRC:.cpp=.o)

CFLAGS  	+=	-Wall -Wextra -Werror

NAME		=	arcade

all: 			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ)

clean:
				@rm -f $(OBJ)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re% 