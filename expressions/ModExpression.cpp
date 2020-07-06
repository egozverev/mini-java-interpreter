#include "ModExpression.h"

ModExpression::ModExpression(
    std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2
) : first(std::move(e1)), second(std::move(e2)) {}

/*int ModExpression::eval() const {
  return first->eval() % second->eval();
}*/

void ModExpression::Accept(Visitor* visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<NumberExpression> ModExpression::GetFirst() {
  return first;
}
std::shared_ptr<NumberExpression> ModExpression::GetSecond() {
  return second;
}