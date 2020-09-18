#include "ModExpression.h"
#include "NumberExpression.h"

ast::ModExpression::ModExpression(
    std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2
) : first(std::move(e1)), second(std::move(e2)) {}

void ast::ModExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::ModExpression::GetFirst() {
  return first;
}
std::shared_ptr<ast::Expression> ast::ModExpression::GetSecond() {
  return second;
}