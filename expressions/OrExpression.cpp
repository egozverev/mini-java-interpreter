#include "OrExpression.h"

OrExpression::OrExpression(BoolExpression *e1, BoolExpression *e2) : first(e1), second(e2) {}

/*bool OrExpression::eval() const {
  return first->eval() || second->eval();
}*/