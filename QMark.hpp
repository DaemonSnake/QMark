//
// QMark.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 14:31:15 2015 bastien penavayre
// Last update Sat Apr 25 01:02:25 2015 bastien penavayre
//

#ifndef QMARK_HH_
# define QMARK_HH_

# include <ostream>
# include "Holder.hpp"

class					QMark
{
private:
  Iholder				*data;

public:
  template				<typename T>
  QMark(T val) {
    data = new Holder<T>(val);
  }
  QMark(QMark const &other) :
    data(other.data->clone())
  {
  }
  template				<typename T>
  bool					isType() {
    return (data->getType() == typeid(T));
  }
  template				<typename T>
  operator T &() {
    return static_cast<T &>((*static_cast<Holder<T> *>(data)));
  }

  virtual ~QMark();
  QMark const 		       		&operator=(QMark const &val);
  std::ostream				&operator>>(std::ostream &) const;
};

std::ostream				&operator<<(std::ostream &, QMark const &);

#endif /* QMARK_HH_ */
