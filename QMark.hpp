//
// QMark.cpp for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 14:31:15 2015 bastien penavayre
// Last update Tue Apr 28 13:11:32 2015 bastien penavayre
//

#ifndef QMARK_HH_
# define QMARK_HH_

# include <ostream>
# include <typeinfo>
# include <ostream>
# include <stdexcept>
# include <string>

class					QMark
{
  // INTERFACE

  class					Iholder
  {
  public:
    virtual				~Iholder() {}
    virtual std::type_info const	&getType() const = 0;
    virtual Iholder			*clone() const = 0;
    virtual void			sendTo(std::ostream &) const = 0;
  };

  // TEMPLATE IMPLEMENTATION OF INTERFACE

  template       			<typename T>
  class					Holder :
    public				Iholder
  {
    T					data;
    std::type_info const * const	type;

  public:
    Holder(T _data) :
      data(_data), type(&typeid(T)) {
    }

    Holder(Holder const *other) :
      data(other->data), type(other->type) {
    }

    virtual				~Holder() {
    }

    virtual std::type_info const       	&getType() const {
      return (*type);
    }

    template				<typename V>
    operator V &() {
      if (typeid(V) == typeid(T))
	return (data);
      throw std::invalid_argument(std::string("Not holder of type ") +
				  std::string(typeid(V).name()));
    }

    virtual Iholder			*clone() const
    {
      return (new Holder(this));
    }

    virtual void	       		sendTo(std::ostream &flux) const {
      flux << data;
    }
  };

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

  template				<typename T>
  T					&as() {
    return (static_cast<T>(*this));
  }

  virtual ~QMark();
  QMark const 		       		&operator=(QMark const &val);
  void					sendTo(std::ostream &) const;
};

std::ostream				&operator<<(std::ostream &, QMark const &);

#endif /* QMARK_HH_ */
