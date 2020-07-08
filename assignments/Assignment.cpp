#include "Assignment.h"

ast::Assignment::Assignment(
    std::shared_ptr<ast::Lvalue> lvalue,
    Driver &driver,
    std::shared_ptr<ast::Expression> expression
) : lvalue_(std::move(lvalue)), expression_(std::move(expression)), driver_(driver) {}

/*void Assignment::execute() const {
  driver_.variables[lvalue_->GetId()] = expression_->eval();
}*/

std::shared_ptr<ast::Lvalue> ast::Assignment::GetLvalue() { return lvalue_; }

std::shared_ptr<ast::Expression> ast::Assignment::GetExpression() { return expression_; }

void ast::Assignment::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}