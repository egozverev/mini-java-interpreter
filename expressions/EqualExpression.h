#pragma once

#include "BoolExpression.h"
#include "NumberExpression.h"

class EqualExpression : public BoolExpression {
public:
  EqualExpression(NumberExpression *e1, NumberExpression *e2);

  bool eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};