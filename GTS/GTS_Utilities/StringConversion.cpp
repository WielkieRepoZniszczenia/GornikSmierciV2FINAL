#ifndef STRING_CONVERSION_H
#define STRING_CONVERSION_H

#include <string>
#include <sstream>

std::string IntToString(int number)
{
    std::ostringstream output;

    if(output << number)
    {
        return output.str();
    }
    return "error";
}

std::string LongToString(long number)
{
    std::ostringstream output;

    if(output << number)
    {
        return output.str();
    }
    return "error";
}

int StringToInt(std::string someSTR)
{
    int number = 0;

    std::istringstream input(someSTR);
    if(input >> number)
    {
        return number;
    }

    return -1;
}

long StringToLong(std::string someSTR)
{
    long number = 0;

    std::istringstream input(someSTR);
    if(input >> number)
    {
        return number;
    }

    return -1;
}


template<class To, class From>
To cast_to(From type)
{
	return static_cast<To>(static_cast<void*>(type));
}

#endif // STRING_CONVERSION_H
