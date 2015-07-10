//
// QMark.cpp for  in /home/penava_b/perso/QMark
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Jul  3 03:56:43 2015 bastien penavayre
// Last update Fri Jul  3 04:03:47 2015 bastien penavayre
//

#include		<QMark.hpp>

QMark::QMark(QMark const &other) :
  data(other.data->clone())
{
}

QMark::~QMark() {
  delete(data);
}

QMark const    		&QMark::operator=(QMark const &val) {
  if (this == &val || data == val.data)
    return (*this);
  delete(data);
  data = val.data->clone();
  return (*this);
}

QMark::Iholder::~Iholder() {
}

void			QMark::sendTo(std::ostream &flux) const {
  data->sendTo(flux);
}

std::ostream	       	&operator<<(std::ostream &flux,
				    QMark const &obj)
{
  obj.sendTo(flux);
  return (flux);
}
