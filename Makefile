##
## Makefile for  in /home/penava_b/perso/libGc
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Tue Jul 14 01:21:59 2015 bastien penavayre
## Last update Tue Jul 14 01:43:07 2015 bastien penavayre
##

SHARED		= libQMark.so
STATIC		= libQMark.a

all:		$(SHARED) clean $(STATIC)

$(SHARED):
		$(MAKE) -f Make/shared.makefile

$(STATIC):
		$(MAKE) -f Make/static.makefile

clean:
		$(MAKE) -f Make/shared.makefile clean
		$(MAKE) -f Make/static.makefile clean

fclean:
		$(MAKE) -f Make/shared.makefile fclean
		$(MAKE) -f Make/static.makefile fclean

re:		fclean all
