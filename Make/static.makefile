##
## Makefile for  in /home/penava_b/perso/ListOf?
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Thu Apr 23 18:34:37 2015 bastien penavayre
## Last update Tue Jul 14 01:44:10 2015 bastien penavayre
##

CC		= g++

RM		= rm -f

NAME		= libQMark.a

SRC		= src/QMark.cpp	\
		src/ListQMark.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror -I ./inc

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rvs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
