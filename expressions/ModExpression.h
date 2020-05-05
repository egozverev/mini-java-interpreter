#pragma once

#include "NumberExpression.h"

class ModExpression : public NumberExpression {
public:
  ModExpression(NumberExpression *e1, NumberExpression *e2);

  //int eval() const override;

  void Accept(Visitor *visitor) override;

  NumberExpression* GetFirst();
  NumberExpression* GetSecond();

private:
  NumberExpression *first;
  NumberExpression *second;
};