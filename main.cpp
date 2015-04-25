//
// main.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Thu Apr 23 16:07:21 2015 bastien penavayre
// Last update Sat Apr 25 01:01:20 2015 bastien penavayre
//

#include <iostream>
#include <list>
#include "QMark.hpp"

int	main()
{
  std::list<QMark>		l;
  QMark				lol(5);

  l.push_back(2.45);
  l.push_back("Salue");
  lol = "hello";
  lol = 42.42;
  static_cast<double &>(lol)++;
  std::cout << lol << std::endl;
}
