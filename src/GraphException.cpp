// GraphException.cpp
#include "GraphException.h"

const char *GraphException::what() const throw()
{
    return "Can't create graph. Incorrect data";
}
