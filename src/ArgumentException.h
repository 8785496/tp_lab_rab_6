#include <exception>

class ArgumentException : public std::exception
{
public:
    const char *what() const throw();
};
