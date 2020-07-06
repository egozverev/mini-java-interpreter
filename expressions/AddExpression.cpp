#include "AddExpression.h"

AddExpression::AddExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2) :
    first(std::move(e1)), second(std::move(e2)) {}

/*int AddExpression::eval() const {
  return first->eval() + second->eval();
}*/

void AddExpression::Accept(Visitor *visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<NumberExpression> AddExpression::GetFirst() {
  return first;
}

std::shared_ptr<NumberExpression> AddExpression::GetSecond() {
  return second;
}