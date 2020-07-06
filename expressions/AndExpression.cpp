#include "AndExpression.h"

AndExpression::AndExpression(std::shared_ptr<BoolExpression> e1, std::shared_ptr<BoolExpression>e2) :
  first(std::move(e1)), second(std::move(e2)) {}

/*bool AndExpression::eval() const {
  return first->eval() && second->eval();
}*/