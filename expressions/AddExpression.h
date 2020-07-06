#pragma once

#include "NumberExpression.h"

#include <memory>

class AddExpression : public NumberExpression, public std::enable_shared_from_this<AddExpression> {
public:
  AddExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2);

  //int eval() const override;

  void Accept(Visitor& visitor) override;

  std::shared_ptr<NumberExpression> GetFirst();
  std::shared_ptr<NumberExpression> GetSecond();

private:
  std::shared_ptr<NumberExpression> first;
  std::shared_ptr<NumberExpression> second;
};