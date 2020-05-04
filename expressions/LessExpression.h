#pragma once

#include "BoolExpression.h"
#include "NumberExpression.h"

class LessExpression : public BoolExpression {
public:
  LessExpression(NumberExpression *e1, NumberExpression *e2);

  bool eval() const override;

private:
  NumberExpression *first;
  NumberExpression *second;
};