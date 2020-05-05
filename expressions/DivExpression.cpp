#include "DivExpression.h"

DivExpression::DivExpression(
    NumberExpression *e1, NumberExpression *e2
) : first(e1), second(e2) {}

/*int DivExpression::eval() const {
  return first->eval() / second->eval();
}*/

void DivExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

NumberExpression* DivExpression::GetFirst() {
  return first;
}
NumberExpression* DivExpression::GetSecond() {
  return second;
}