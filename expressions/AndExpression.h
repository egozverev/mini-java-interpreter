#pragma once

#include "BoolExpression.h"

class AndExpression : public BoolExpression {
public:
  AndExpression(BoolExpression *e1, BoolExpression *e2);

  //bool eval() const override;



private:
  BoolExpression *first;
  BoolExpression *second;
};