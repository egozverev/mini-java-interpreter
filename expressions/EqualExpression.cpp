#include "EqualExpression.h"

EqualExpression::EqualExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2) :
  first(std::move(e1)), second(std::move(e2)) {}

/*bool EqualExpression::eval() const {
  return first->eval() == second->eval();
}*/