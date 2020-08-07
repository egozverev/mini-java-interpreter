#include "AndExpression.h"
#include "BoolExpression.h"

ast::AndExpression::AndExpression(std::shared_ptr<Expression> e1, std::shared_ptr<Expression>e2) :
  first(std::move(e1)), second(std::move(e2)) {}

void ast::AndExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::AndExpression::GetFirst() {
  return first;
}

std::shared_ptr<ast::Expression> ast::AndExpression::GetSecond() {
  return second;
}