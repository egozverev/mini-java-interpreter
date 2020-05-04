#include "GreaterExpression.h"

GreaterExpression::GreaterExpression(NumberExpression *e1, NumberExpression *e2) : first(e1), second(e2) {}

bool GreaterExpression::eval() const {
  return first->eval() > second->eval();
}