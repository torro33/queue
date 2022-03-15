#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>

class UnderFlowException : public std::exception {
public:
  const char *what() const noexcept { return "Alulcsordulas!"; }
};

#endif // LISTEXCEPTION_HPP_INCLUDED
