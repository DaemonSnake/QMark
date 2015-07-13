##
## Makefile for  in /home/penava_b/perso/ListOf?
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Thu Apr 23 18:34:37 2015 bastien penavayre
## Last update Tue Jul 14 01:44:02 2015 bastien penavayre
##

CC		= g++

RM		= rm -f

NAME		= libQMark.so

SRC		= src/QMark.cpp	\
		src/ListQMark.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror -fPIC -I ./inc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -shared
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
