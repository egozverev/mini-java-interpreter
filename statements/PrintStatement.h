#pragma once

#include "Statement.h"
#include "expressions/Expression.h"

class PrintStatement : public Statement {
public:
  explicit PrintStatement(Expression *expression);

  //void execute() const override;

  void Accept(Visitor *visitor) override;

  Expression* GetExpression();

private:
  Expression *expression_;
};