#include "PrintStatement.h"
#include <iostream>

ast::PrintStatement::PrintStatement(std::shared_ptr<ast::Expression> expression) : expression_(std::move(expression)) {}

/*void PrintStatement::execute() const {
  std::cout << expression_->eval() << "\n";
}*/

void ast::PrintStatement::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}

std::shared_ptr<ast::Expression> ast::PrintStatement::GetExpression() { return expression_; }