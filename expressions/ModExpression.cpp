#include "ModExpression.h"
#include "NumberExpression.h"

ast::ModExpression::ModExpression(
    std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2
) : first(std::move(e1)), second(std::move(e2)) {}

/*int ModExpression::eval() const {
  return first->eval() % second->eval();
}*/

void ast::ModExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::NumberExpression> ast::ModExpression::GetFirst() {
  return first;
}
std::shared_ptr<ast::NumberExpression> ast::ModExpression::GetSecond() {
  return second;
}