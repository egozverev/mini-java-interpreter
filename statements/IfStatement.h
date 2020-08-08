#pragma once

#include "Statement.h"
#include "expressions/Expression.h"

#include <memory>

namespace ast {
  class IfStatement : public ast::Statement, public std::enable_shared_from_this<IfStatement> {
  public:
    explicit IfStatement(
        std::shared_ptr<Expression> expression,
        std::shared_ptr<Statement> statement
    );

    void Accept(Visitor& visitor) override;

    std::shared_ptr<Expression> GetExpression();

    std::shared_ptr<Statement> GetStatement();


  private:
    std::shared_ptr<Expression> expression_;
    std::shared_ptr<Statement> statement_;

  };
}