#include "IfStatement.h"

namespace ast {
  IfStatement::IfStatement(std::shared_ptr<Expression> expression,
                           std::shared_ptr<Statement> statement) : expression_(std::move(expression)),
                                                                   statement_(std::move(statement)) {}

  std::shared_ptr<Expression> IfStatement::GetExpression() { return expression_; }

  std::shared_ptr<Statement> IfStatement::GetStatement() { return statement_;}


  void IfStatement::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }
}
