//
// QMark.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 21:56:55 2015 bastien penavayre
// Last update Sat Apr 25 00:13:06 2015 bastien penavayre
//

#include "QMark.hpp"

QMark::~QMark() {
  delete(data);
}

QMark const    	       		&QMark::operator=(QMark const &val) {
  if (this == &val || data == val.data)
    return (*this);
  delete(data);
  data = val.data->clone();
  return (*this);
}

std::ostream				&QMark::operator>>(std::ostream &flux) const
{
  return *data >> flux;
}

std::ostream				&operator<<(std::ostream &flux,
						    QMark const &obj)
{
  return obj >> flux;
}
