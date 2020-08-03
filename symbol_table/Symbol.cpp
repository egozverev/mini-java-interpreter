#include "Symbol.h"

#include <iostream>

Symbol::Symbol(const std::string& name): name_(name) {}

bool Symbol::operator==(const Symbol& other) const {
    return name_ == other.name_;
}

bool Symbol::operator!=(const Symbol& other) const {
    return name_ != other.name_;
}



std::string Symbol::GetName() const {
    return name_;
}




