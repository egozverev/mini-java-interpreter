#include "EqualExpression.h"

EqualExpression::EqualExpression(NumberExpression *e1, NumberExpression *e2) : first(e1), second(e2) {}

/*bool EqualExpression::eval() const {
  return first->eval() == second->eval();
}*/