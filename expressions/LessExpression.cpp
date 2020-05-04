#include "LessExpression.h"

LessExpression::LessExpression(NumberExpression *e1, NumberExpression *e2) : first(e1), second(e2) {}

bool LessExpression::eval() const {
  return first->eval() < second->eval();
}