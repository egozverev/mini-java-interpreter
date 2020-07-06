#include "Assignment.h"

Assignment::Assignment(
    std::shared_ptr<Lvalue> lvalue,
    Driver &driver,
    std::shared_ptr<Expression> expression
) : lvalue_(std::move(lvalue)), expression_(std::move(expression)), driver_(driver) {}

/*void Assignment::execute() const {
  driver_.variables[lvalue_->GetId()] = expression_->eval();
}*/

std::shared_ptr<Lvalue> Assignment::GetLvalue() { return lvalue_; }

std::shared_ptr<Expression> Assignment::GetExpression() { return expression_; }

void Assignment::Accept(Visitor *visitor) {
  visitor->Visit(this->shared_from_this());
}