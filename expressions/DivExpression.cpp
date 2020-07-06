#include "DivExpression.h"

DivExpression::DivExpression(
    std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2
) : first(std::move(e1)), second(std::move(e2)) {}

/*int DivExpression::eval() const {
  return first->eval() / second->eval();
}*/

void DivExpression::Accept(Visitor* visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<NumberExpression> DivExpression::GetFirst() {
  return first;
}
std::shared_ptr<NumberExpression> DivExpression::GetSecond() {
  return second;
}