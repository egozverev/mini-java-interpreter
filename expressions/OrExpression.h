#pragma once

#include "BoolExpression.h"

#include <memory>

class OrExpression : public BoolExpression, public std::enable_shared_from_this<OrExpression> {
public:
  OrExpression(std::shared_ptr<BoolExpression> e1, std::shared_ptr<BoolExpression> e2);

  //bool eval() const override;


private:
  std::shared_ptr<BoolExpression> first;
  std::shared_ptr<BoolExpression> second;
};