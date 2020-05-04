#pragma once

#include "NumberExpression.h"

class AddExpression : public NumberExpression {
public:
  AddExpression(NumberExpression *e1, NumberExpression *e2);

  int eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};