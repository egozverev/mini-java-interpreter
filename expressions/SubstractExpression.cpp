#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2):
  first(std::move(e1)), second(std::move(e2)) {}

/*int SubstractExpression::eval() const {
    return first->eval() - second->eval();
}*/

void SubstractExpression::Accept(Visitor* visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<NumberExpression> SubstractExpression::GetFirst() {
  return first;
}
std::shared_ptr<NumberExpression> SubstractExpression::GetSecond() {
  return second;
}