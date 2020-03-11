##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

INC_DIR		= include/

CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra

RM		= rm -f

CC		=	gcc

NAME		=	lib_arcade_gameone.so

SRCS_DIR	=	src/
SRCS_FILES	=	main.c 					

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

CFLAGS  +=      -Wall -Wextra -fpic -I $(DIR_INC)

MAKEFLAGS +=	--no-print-directory


all: $(NAME)
	cp	$(NAME) ../

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re