Welcome to Boost.Either
=======================

Boost.Either is a potential boost library that relates to Boost.Variant how
std::pair relates to std::tuple. This repository is a proof of concept
implementation intended to help the discussion.

Semantics
---------

```c++
template< typename left_type, typename right_type>
struct either
{
  // postcondition, is_left()
  either( left_type );

  // postcondition, is_right()
  either( right_type );

  bool is_left() const;
  bool is_right() const;

  // postcondition, is_left()
  either & operator=( left_type );

  // postcondition, is_right()
  either & operator=( right_type );

  // precondition, is_left()
  left_type left();

  // precondition, is_right()
  right_type right();
private:
};
```

Uses
----

### Use 1: Can be used as an alternative to exceptions or the (error codes+set reference idiom):

```c++
either<error_code, file_id> load_file(...);
```

vs.

```c++
error_code load_file( file_id &, ... );
```

or

```c++
// throws std::exception
file_id load_file(...);
```

### Use 2: A lightweight alternative to boost::variant when only 2 components are required (either relates to variant in a similar way that pair relates to tuple ).

```c++
variant<A,B> eitherAOrB;
if( A * aPtr = boost::get<A>( &eitherAOrB ) )
  std::cout << "A: " << *aPtr;
else
  std::cout << "B: " << boost::get<B>( eitherAOrB );
```

vs.

```c++
either<A,B> eitherAOrB;

if( eitherAOrB.is_left() )
  std::cout << "A: " << eitherAOrB.left();
else
  std::cout << "B: " << eitherAOrB.right();
```
