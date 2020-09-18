#include "IdentExpression.h"

ast::IdentExpression::IdentExpression(const std::string &ident, Driver &driver) : ident_(ident), driver_(driver) {}

void ast::IdentExpression::Accept(Visitor &visitor) {
  visitor.Visit(this->shared_from_this());
}

std::string ast::IdentExpression::GetIdent() {
  return ident_;
}