##
## Makefile for  in /home/penava_b/perso/QMark/Example
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Fri Jul  3 04:14:14 2015 bastien penavayre
## Last update Thu Jul  9 20:50:43 2015 bastien penavayre
##

CXX		= g++

RM		= rm -f

NAME		= test

SRC		= main.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror -I ../inc/

LINKFLAGS	= $(CXXFLAGS) -Wl,-rpath=../ -lQMark -L../

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) all -C ../
		$(CXX) $(OBJ) -o $(NAME) $(LINKFLAGS)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
