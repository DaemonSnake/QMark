//
// QMark.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 14:31:15 2015 bastien penavayre
// Last update Sat Jul 11 02:34:51 2015 bastien penavayre
//

#pragma					once

#include				<ostream>
#include				<typeinfo>
#include				<ostream>
#include				<stdexcept>
#include				<string>

class					QMark
{
#include				<QMarkTools.hpp>

  Iholder				*data;

public:
  template				<typename T>
  QMark(T val) {
    data = new Holder<T>(val);
  }

  template				<typename T>
  bool					isType() const {
    return (data->getType() == typeid(T));
  }

  template				<typename T>
  operator T &() {
    return static_cast<T &>((*static_cast<Holder<T> *>(data)));
  }

  template				<typename T>
  T					&as() {
    return (static_cast<T>(*this));
  }

  template				<class T>
  bool					operator==(T val) const {
    if (isType<T>() && static_cast<T &>(*static_cast<Holder<T> *>(data)) == val)
      return true;
    return false;
  }

  QMark(QMark const &);
  ~QMark();
  QMark const				&operator=(QMark const &);
  void					sendTo(std::ostream &) const;
};

std::ostream				&operator<<(std::ostream &,
						    QMark const &);
