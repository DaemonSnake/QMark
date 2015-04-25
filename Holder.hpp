//
// Holder.hh for  in /home/penava_b/perso/ListOf?
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Fri Apr 24 22:47:31 2015 bastien penavayre
// Last update Sat Apr 25 01:02:44 2015 bastien penavayre
//

#ifndef REFHOLDER_HPP
#define REFHOLDER_HPP

# include <typeinfo>
# include <ostream>
# include <stdexcept>
# include <string>

class		       		Iholder
{
public:
  virtual		       	~Iholder() {}
  virtual std::type_info const	&getType() const = 0;
  virtual Iholder	       	*clone() const = 0;
  virtual std::ostream		&operator>>(std::ostream &) const = 0;
};

template       			<typename T>
class		       		Holder :
  public			Iholder
{
  T		      	       	data;
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

  virtual std::type_info const		&getType() const {
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

  virtual std::ostream		&operator>>(std::ostream &flux) const {
    return flux << data;
  }
};

#endif /* REFHOLDER_HPP */
