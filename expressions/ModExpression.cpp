#include "ModExpression.h"

ModExpression::ModExpression(
    NumberExpression *e1, NumberExpression *e2
) : first(e1), second(e2) {}

/*int ModExpression::eval() const {
  return first->eval() % second->eval();
}*/

void ModExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

NumberExpression* ModExpression::GetFirst() {
  return first;
}
NumberExpression* ModExpression::GetSecond() {
  return second;
}