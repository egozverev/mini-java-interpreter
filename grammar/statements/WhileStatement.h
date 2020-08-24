#pragma once

#include "Statement.h"

namespace ast {
  class WhileStatement : public Statement, public std::enable_shared_from_this<WhileStatement> {
  public:
    WhileStatement(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> statement);

    void Accept(Visitor &visitor) override;

    std::shared_ptr<Expression> GetExpr();

    std::shared_ptr<Statement> GetStatement();

  private:
    std::shared_ptr<Expression> expr_;
    std::shared_ptr<Statement> statement_;
  };
}