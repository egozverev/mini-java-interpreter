#pragma once

#include "NumberExpression.h"

class MulExpression : public NumberExpression {
public:
  MulExpression(NumberExpression *e1, NumberExpression *e2);

  int eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};