#pragma once

#include "Statement.h"
#include "grammar/expressions/Expression.h"

#include <memory>

namespace ast {
  class IfElseStatement : public ast::Statement, public std::enable_shared_from_this<IfElseStatement> {
  public:
    explicit IfElseStatement(
        std::shared_ptr<Expression> expression,
        std::shared_ptr<Statement> true_statement,
        std::shared_ptr<Statement> false_statement
        );

    void Accept(Visitor& visitor) override;

    std::shared_ptr<Expression> GetExpression();

    std::shared_ptr<Statement> GetTrueStatement();

    std::shared_ptr<Statement> GetFalseStatement();

  private:
    std::shared_ptr<Expression> expression_;
    std::shared_ptr<Statement> true_statement_;
    std::shared_ptr<Statement> false_statement_;

  };
}