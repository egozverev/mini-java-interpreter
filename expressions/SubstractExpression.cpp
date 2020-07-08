#include "SubstractExpression.h"

ast::SubstractExpression::SubstractExpression(std::shared_ptr<ast::NumberExpression> e1, std::shared_ptr<ast::NumberExpression> e2):
  first(std::move(e1)), second(std::move(e2)) {}

/*int SubstractExpression::eval() const {
    return first->eval() - second->eval();
}*/

void ast::SubstractExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::NumberExpression> ast::SubstractExpression::GetFirst() {
  return first;
}
std::shared_ptr<ast::NumberExpression> ast::SubstractExpression::GetSecond() {
  return second;
}