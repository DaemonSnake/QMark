//
// main.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Thu Apr 23 16:07:21 2015 bastien penavayre
// Last update Fri Jul 17 03:03:33 2015 bastien penavayre
//

#include <iostream>
#include <list>
#include <QMark.hpp>
#include <ListQMark.hpp>

int	main()
{
  ListQMark			l;
  QMark				lol(5);

  l.push_back(2.45);
  l.push_back("Hello");
  l.push_back(100);
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
  const std::list<int>		&in = l.sub<int>();

  for (std::list<int>::const_iterator it = in.begin();
       it != in.end(); it++) {
    std::cout << *it << std::endl;
  }
}
