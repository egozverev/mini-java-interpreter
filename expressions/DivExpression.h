#pragma once

#include "NumberExpression.h"

class DivExpression : public NumberExpression {
public:
  DivExpression(NumberExpression *e1, NumberExpression *e2);

  int eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};