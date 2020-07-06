#include "IdentExpression.h"

IdentExpression::IdentExpression(const std::string& ident, Driver& driver): ident_(ident), driver_(driver) {}

/*int IdentExpression::eval() const {
    return driver_.variables[ident_];
}*/

void IdentExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::string IdentExpression::GetIdent() {
  return ident_;
}