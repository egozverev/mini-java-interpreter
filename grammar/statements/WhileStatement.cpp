#include "WhileStatement.h"

namespace ast {
  WhileStatement::WhileStatement(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> statement):
  expr_(std::move(expr)), statement_(std::move(statement)){}

  void WhileStatement::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  std::shared_ptr<Expression> WhileStatement::GetExpr() {
    return expr_;
  }

  std::shared_ptr<Statement> WhileStatement::GetStatement() {
    return statement_;
  }
}