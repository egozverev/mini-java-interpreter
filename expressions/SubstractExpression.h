#pragma once

#include "NumberExpression.h"

class SubstractExpression : public NumberExpression {
public:
  SubstractExpression(NumberExpression *e1, NumberExpression *e2);

  //int eval() const override;

  void Accept(Visitor *visitor) override;

  NumberExpression* GetFirst();
  NumberExpression* GetSecond();

private:
  NumberExpression *first;
  NumberExpression *second;
};