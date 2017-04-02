// ArgumentException.cpp
#include "ArgumentException.h"

const char *ArgumentException::what() const throw()
{
    return "Incorrect arguments";
}
