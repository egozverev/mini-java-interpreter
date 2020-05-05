#include "AndExpression.h"

AndExpression::AndExpression(BoolExpression *e1, BoolExpression *e2) : first(e1), second(e2) {}

/*bool AndExpression::eval() const {
  return first->eval() && second->eval();
}*/