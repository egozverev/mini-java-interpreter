#include "OrExpression.h"
#include "BoolExpression.h"

ast::OrExpression::OrExpression(std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2) :
  first(std::move(e1)), second(std::move(e2)) {}

void ast::OrExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::OrExpression::GetFirst() {
  return first;
}

std::shared_ptr<ast::Expression> ast::OrExpression::GetSecond() {
  return second;
}