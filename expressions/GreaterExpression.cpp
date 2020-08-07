#include "GreaterExpression.h"

ast::GreaterExpression::GreaterExpression(std::shared_ptr<ast::Expression> e1, std::shared_ptr<ast::Expression> e2) :
    first(std::move(e1)), second(std::move(e2)) {}

void ast::GreaterExpression::Accept(Visitor &visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::GreaterExpression::GetFirst() {
  return first;
}

std::shared_ptr<ast::Expression> ast::GreaterExpression::GetSecond() {
  return second;
}