#pragma once

#include "NumberExpression.h"

class SubstractExpression : public NumberExpression {
public:
  SubstractExpression(NumberExpression *e1, NumberExpression *e2);

  int eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};