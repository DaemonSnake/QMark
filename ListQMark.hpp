//
// ListQMark.hpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Mon Apr 27 11:27:29 2015 bastien penavayre
// Last update Thu Apr 30 11:35:18 2015 bastien penavayre
//

#ifndef LISTQMARK_HPP_
# define LISTQMARK_HPP_

# include <list>
# include "QMark.hpp"

class			ListQMark :
  public		std::list<QMark>
{
public:
  ListQMark();
  virtual		~ListQMark();

  template		<typename T>
  void			operator ()(T obj) {
    push_back(obj);
  }

  template		<typename T>
  T			get(int index = 0) {
    int			i = -1;

    for (std::list<QMark>::iterator it = begin();
	 it != end(); it++)
      if ((*it).isType<T>() && index == ++i)
	return (static_cast<T>(*it));
    throw std::invalid_argument("No such type");
  }

  template		<typename T>
  std::list<T>		sub() {
    std::list<T>	tmp;
    for (std::list<QMark>::iterator it = begin();
	 it != end(); it++)
      if ((*it).isType<T>())
	tmp.push_back(*it);
    return (tmp);
  }
};

#endif /* LISTQMARK_HPP_ */
