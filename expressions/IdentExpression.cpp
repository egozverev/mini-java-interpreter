#include "IdentExpression.h"

IdentExpression::IdentExpression(const std::string& ident, Driver& driver): ident_(ident), driver_(driver) {}

int IdentExpression::eval() const {
    return driver_.variables[ident_];
}