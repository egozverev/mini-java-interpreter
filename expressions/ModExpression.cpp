#include "ModExpression.h"

ModExpression::ModExpression(
    NumberExpression *e1, NumberExpression *e2
) : first(e1), second(e2) {}

int ModExpression::eval() const {
  return first->eval() % second->eval();
}