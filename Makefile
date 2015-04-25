##
## Makefile for  in /home/penava_b/perso/ListOf?
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Thu Apr 23 18:34:37 2015 bastien penavayre
## Last update Fri Apr 24 23:11:38 2015 bastien penavayre
##

CC		= g++

RM		= rm -f

NAME		= test

SRC		= main.cpp	\
		QMark.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
