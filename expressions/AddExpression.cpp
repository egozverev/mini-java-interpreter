#include "AddExpression.h"

ast::AddExpression::AddExpression(std::shared_ptr<ast::NumberExpression> e1, std::shared_ptr<ast::NumberExpression> e2) :
    first(std::move(e1)), second(std::move(e2)) {}

/*int AddExpression::eval() const {
  return first->eval() + second->eval();
}*/

void ast::AddExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::NumberExpression> ast::AddExpression::GetFirst() {
  return first;
}

std::shared_ptr<ast::NumberExpression> ast::AddExpression::GetSecond() {
  return second;
}