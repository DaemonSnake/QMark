//
// QMarkTools.hpp for  in /home/penava_b/perso/test/QMark/inc
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Tue Jul  7 20:37:45 2015 bastien penavayre
// Last update Tue Jul 14 06:50:55 2015 bastien penavayre
//

#pragma				once

// INTERFACE

struct		       		Iholder
{
  virtual	       		~Iholder();
  virtual std::type_info const	&getType() const = 0;
  virtual Iholder      		*clone() const = 0;
  virtual void			sendTo(std::ostream &) const = 0;
};

// TEMPLATE IMPLEMENTATION OF INTERFACE

template       			<typename T>
class			       	Holder :
  public	       		Iholder
{
  T	       			data;
  std::type_info const * const	type;

public:
  Holder(T _data) :
    data(_data), type(&typeid(T)) {
  }

  Holder(Holder const *other) :
    data(other->data), type(other->type) {
  }

  virtual      			~Holder() {
  }

  virtual std::type_info const	&getType() const {
    return (*type);
  }

  template		       	<typename V>
  operator V &() {
    if (typeid(V) == typeid(T))
      return (data);
    throw std::invalid_argument(std::string("Not holder of type ") +
				std::string(typeid(V).name()));
  }

  virtual Iholder      		*clone() const
  {
    return (new Holder(this));
  }

  virtual void	       		sendTo(std::ostream &flux) const {
    flux << data;
  }
};
