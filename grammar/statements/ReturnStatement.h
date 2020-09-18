#pragma once

#include "Statement.h"

namespace ast {
  class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement> {
  public:
    explicit ReturnStatement(std::shared_ptr<Expression> expr);
    void Accept(Visitor& visitor);
    std::shared_ptr<Expression> GetExpr();

  private:
    std::shared_ptr<Expression> expr_;
  };
}