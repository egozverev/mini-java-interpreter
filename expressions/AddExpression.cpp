#include "AddExpression.h"

ast::AddExpression::AddExpression(std::shared_ptr<ast::Expression> e1, std::shared_ptr<ast::Expression> e2) :
    first(std::move(e1)), second(std::move(e2)) {}

/*int AddExpression::eval() const {
  return first->eval() + second->eval();
}*/

void ast::AddExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::AddExpression::GetFirst() {
  return first;
}

std::shared_ptr<ast::Expression> ast::AddExpression::GetSecond() {
  return second;
}