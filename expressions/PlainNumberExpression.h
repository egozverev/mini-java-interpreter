#pragma once

#include "NumberExpression.h"

class PlainNumberExpression : public NumberExpression {
public:
  explicit PlainNumberExpression(int value);

  //int eval() const override;

  void Accept(Visitor *visitor) override;

  int value;

};