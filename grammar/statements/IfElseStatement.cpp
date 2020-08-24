#include "IfElseStatement.h"

namespace ast {
  IfElseStatement::IfElseStatement(std::shared_ptr<Expression> expression,
                                   std::shared_ptr<Statement> true_statement, std::shared_ptr<Statement>
                           false_statement) : expression_(std::move(expression)),
                                              true_statement_(std::move(true_statement)),
                                              false_statement_(std::move(false_statement)) {}

  std::shared_ptr<Expression> IfElseStatement::GetExpression() {return expression_;}
  std::shared_ptr<Statement> IfElseStatement::GetTrueStatement() {return true_statement_;}
  std::shared_ptr<Statement> IfElseStatement::GetFalseStatement() {return false_statement_;}

  void IfElseStatement::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }
}
