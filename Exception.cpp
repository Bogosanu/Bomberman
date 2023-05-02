
#include "Exception.h"

#include <utility>
Exception::Exception(const std::string& message) : message1(message) {}

const char* Exception::what() const noexcept {
    return message1.c_str();
}