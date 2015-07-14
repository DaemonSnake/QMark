##
## Makefile for  in /home/penava_b/perso/libGc
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Tue Jul 14 01:21:59 2015 bastien penavayre
## Last update Tue Jul 14 03:29:22 2015 bastien penavayre
##

CC		= g++

RM		= rm -f

SHARED		= libQMark.so

STATIC		= libQMark.a

SRC		= src/QMark.cpp	\
		src/ListQMark.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror -fPIC -I ./inc

all:		$(SHARED) $(STATIC)

$(SHARED):	$(OBJ)
		$(CC) $(OBJ) -o $(SHARED) -shared

$(STATIC):	$(OBJ)
		ar rvs $(STATIC) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(SHARED) $(STATIC)

re:		fclean all
