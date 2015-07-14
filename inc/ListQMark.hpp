//
// ListQMark.hpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Mon Apr 27 11:27:29 2015 bastien penavayre
// Last update Tue Jul 14 04:47:00 2015 bastien penavayre
//

#pragma			once

# include		<list>
# include		"QMark.hpp"

struct			ListQMark :
  public		std::list<QMark>
{
  ListQMark();
  virtual		~ListQMark();

  template		<typename T>
  void			operator ()(T const &obj) {
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
    return tmp;
  }
};
