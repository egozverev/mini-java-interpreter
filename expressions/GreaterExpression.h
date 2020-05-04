#pragma once

#include "BoolExpression.h"
#include "NumberExpression.h"

class GreaterExpression : public BoolExpression {
public:
  GreaterExpression(NumberExpression *e1, NumberExpression *e2);

  bool eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};