#pragma once

#include "Expression.h"

class NumberExpression : public Expression {
public:
  virtual int eval() const = 0;
};