//
// main.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Thu Apr 23 16:07:21 2015 bastien penavayre
// Last update Fri Jul  3 04:13:53 2015 bastien penavayre
//

#include <iostream>
#include <list>
#include <QMark.hpp>
#include <ListQMark.hpp>

int	main()
{
  ListQMark			l;
  QMark				lol(5);

  l(2.45);
  l("Hello");
  l(100);
  l.get<int &>()++;
  try {
    std::cout << l.get<int>() << std::endl;
    std::cout << l.get<char const *>() << std::endl;
    std::cout << l.get<int>(1) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  lol = "hello";
  lol = 42.42;
  lol.as<double &>()++;
  ((double &)(lol))++;
  std::cout << lol << std::endl;
  std::list<int>		in = l.sub<int>();
  for (std::list<int>::iterator it = in.begin();
       it != in.end(); it++) {
    std::cout << *it << std::endl;
  }
}
