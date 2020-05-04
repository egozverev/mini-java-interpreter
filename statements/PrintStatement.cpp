#include "PrintStatement.h"
#include <iostream>

PrintStatement::PrintStatement(Expression *expression) : expression_(expression) {}

void PrintStatement::execute() const {
  std::cout << expression_->eval() << "\n";
}