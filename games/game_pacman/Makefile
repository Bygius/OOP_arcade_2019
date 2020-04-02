##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

INC_DIR		= include/
INT_DIR		= ../../include/

CXXFLAGS		+= -I $(INC_DIR)
CXXFLAGS		+= -I $(INT_DIR)
CXXFLAGS		+= -Wall -Wextra -fpic -rdynamic

RM		= rm -f

CC		=	g++

NAME		=	lib_arcade_pacman.so

SRCS_DIR	=	src/
SRCS_FILES	=	Pacman.cpp \
				Player.cpp \
				Map.cpp

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.cpp=.o)

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