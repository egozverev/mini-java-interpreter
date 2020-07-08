#include "MulExpression.h"

ast::MulExpression::MulExpression(
    std::shared_ptr<ast::NumberExpression> e1, std::shared_ptr<ast::NumberExpression> e2
): first(std::move(e1)), second(std::move(e2)) {}

/*int MulExpression::eval() const {
    return first->eval() * second->eval();
}*/

void ast::MulExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::NumberExpression> ast::MulExpression::GetFirst() {
  return first;
}
std::shared_ptr<ast::NumberExpression> ast::MulExpression::GetSecond() {
  return second;
}