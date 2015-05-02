//
// QMark.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 21:56:55 2015 bastien penavayre
// Last update Sun Apr 26 08:57:07 2015 bastien penavayre
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

void					QMark::sendTo(std::ostream &flux) const
{
  data->sendTo(flux);
}

std::ostream				&operator<<(std::ostream &flux,
						    QMark const &obj)
{
  obj.sendTo(flux);
  return (flux);
}
