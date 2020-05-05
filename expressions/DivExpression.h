#pragma once

#include "NumberExpression.h"

class DivExpression : public NumberExpression {
public:
  DivExpression(NumberExpression *e1, NumberExpression *e2);

  //int eval() const override;

  void Accept(Visitor *visitor) override;

  NumberExpression* GetFirst();
  NumberExpression* GetSecond();

private:
  NumberExpression *first;
  NumberExpression *second;
};