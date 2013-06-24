#include <boost/variant.hpp>

namespace boost {

template< typename left_type, typename right_type>
struct either
{
  // postcondition, is_left()
  either( const left_type & lt )
      : impl( lt )
  {
  }

  // postcondition, is_left()
  either( left_type && lt )
      : impl( std::move( lt ) )
  {
  }

  // postcondition, is_right()
  either( const right_type & rt )
      : impl( rt )
  {
  }

  // postcondition, is_right()
  either( right_type && rt )
      : impl( std::move( rt ) )
  {
  }

  bool is_left() const
  {
      return boost::get< left_type >( &impl ) != 0;
  }
  bool is_right() const
  {
      return !is_left();
  }

  // postcondition, is_left()
  either & operator=( const left_type & lt )
  {
      impl = lt;
      return *this;
  }

  // postcondition, is_left()
  either & operator=( const left_type && lt )
  {
      impl = std::move( lt );
      return *this;
  }

  // postcondition, is_right()
  either & operator=( const right_type & rt )
  {
      impl = rt;
      return *this;
  }

  // postcondition, is_right()
  either & operator=( const right_type && rt )
  {
      impl = std::move( rt );
      return *this;
  }

  // precondition, is_left()
  left_type left()
  {
      return *boost::get< left_type >( &impl );
  }

  // precondition, is_right()
  right_type right()
  {
      return *boost::get< right_type >( &impl );
  }
private:
  boost::variant< left_type, right_type > impl;
};

}
