#include "DivExpression.h"
#include "NumberExpression.h"

ast::DivExpression::DivExpression(
    std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2
) : first(std::move(e1)), second(std::move(e2)) {}

void ast::DivExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::DivExpression::GetFirst() {
  return first;
}
std::shared_ptr<ast::Expression> ast::DivExpression::GetSecond() {
  return second;
}