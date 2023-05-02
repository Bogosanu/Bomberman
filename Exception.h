

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
public:


    explicit Exception(const std::string& message);

    virtual const char* what() const noexcept override;

private:
    std::string message1;
};

class Outofbounds : public Exception {
public:
    Outofbounds() : Exception("Out of bounds position. \n") {}
};

#endif //OOP_EXCEPTION_H
