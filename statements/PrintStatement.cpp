#include "PrintStatement.h"
#include <iostream>

PrintStatement::PrintStatement(Expression *expression) : expression_(expression) {}

/*void PrintStatement::execute() const {
  std::cout << expression_->eval() << "\n";
}*/

void PrintStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

Expression *PrintStatement::GetExpression() { return expression_; }