#include <boost/either.hpp>
#include <iostream>

int main()
{
    boost::either< int, char > thing = 33;
    std::cout << "isLeft=" << thing.is_left() << std::endl;
    thing = 'a';
    std::cout << "isRight=" << thing.is_right() << std::endl;
    std::cout << "rightVal=" << thing.right() << std::endl;
}
