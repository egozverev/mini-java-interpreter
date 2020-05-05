#include "AddExpression.h"

AddExpression::AddExpression(NumberExpression *e1, NumberExpression *e2) : first(e1), second(e2) {}

/*int AddExpression::eval() const {
  return first->eval() + second->eval();
}*/

void AddExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

NumberExpression* AddExpression::GetFirst() {
  return first;
}
NumberExpression* AddExpression::GetSecond() {
  return second;
}