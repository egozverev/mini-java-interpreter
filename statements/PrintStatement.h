#pragma once

#include "Statement.h"
#include "expressions/Expression.h"

#include <memory>

class PrintStatement : public Statement, public std::enable_shared_from_this<PrintStatement> {
public:
  explicit PrintStatement(std::shared_ptr<Expression> expression);

  //void execute() const override;

  void Accept(Visitor *visitor) override;

  std::shared_ptr<Expression> GetExpression();

private:
  std::shared_ptr<Expression> expression_;
};