##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

INC_DIR		= ./include/
INT_DIR		= ../../include/

CXXFLAGS		+= -I $(INC_DIR)
CXXFLAGS		+= -Wall -Wextra -fPIC -rdynamic
CXXFLAGS		+= -I $(INT_DIR)
CXXFLAGS		+= -lsfml-graphics -lsfml-window -lsfml-system

RM		=	rm -f

CC		=	g++

NAME		=	lib_arcade_sfml.so

SRCS_DIR	=	src/

SRCS_FILES	=   Libsfml.cpp \

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)
	cp	$(NAME) ../

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) -shared -rdynamic -g

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re