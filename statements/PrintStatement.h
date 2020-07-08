#pragma once

#include "Statement.h"
#include "expressions/Expression.h"

#include <memory>

namespace ast {
  class PrintStatement : public ast::Statement, public std::enable_shared_from_this<PrintStatement> {
  public:
    explicit PrintStatement(std::shared_ptr<Expression> expression);

    //void execute() const override;

    void Accept(Visitor& visitor) override;

    std::shared_ptr<Expression> GetExpression();

  private:
    std::shared_ptr<Expression> expression_;
  };
}