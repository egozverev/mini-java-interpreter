#include "MulExpression.h"

MulExpression::MulExpression(
    std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2
): first(std::move(e1)), second(std::move(e2)) {}

/*int MulExpression::eval() const {
    return first->eval() * second->eval();
}*/

void MulExpression::Accept(Visitor* visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<NumberExpression> MulExpression::GetFirst() {
  return first;
}
std::shared_ptr<NumberExpression> MulExpression::GetSecond() {
  return second;
}