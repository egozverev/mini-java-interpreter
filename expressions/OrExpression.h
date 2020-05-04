#pragma once

#include "BoolExpression.h"

class OrExpression : public BoolExpression {
public:
  OrExpression(BoolExpression *e1, BoolExpression *e2);

  bool eval() const override;

private:
  BoolExpression *first;
  BoolExpression *second;
};