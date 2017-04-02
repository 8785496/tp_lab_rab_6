#include <iostream>
#include <exception>

class GraphException : public std::exception
{
public:
    const char *what() const throw();
};
