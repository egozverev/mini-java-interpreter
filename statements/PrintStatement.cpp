#include "PrintStatement.h"
#include <iostream>

PrintStatement::PrintStatement(std::shared_ptr<Expression> expression) : expression_(std::move(expression)) {}

/*void PrintStatement::execute() const {
  std::cout << expression_->eval() << "\n";
}*/

void PrintStatement::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<Expression> PrintStatement::GetExpression() { return expression_; }