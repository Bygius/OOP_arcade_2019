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
CXXFLAGS		+= -lncurses

RM		=	rm -f

CC		=	gcc

NAME		=	lib_arcade_ncurses.so

SRCS_DIR	=	src/
SRCS_FILES	=	Libncurses.cpp

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.cpp=.o)

MAKEFLAGS +=	--no-print-directory


all: $(NAME)
	cp	$(NAME) ../

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) -shared -rdynamic

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re