#pragma once

#include "BoolExpression.h"
#include "NumberExpression.h"

#include <memory>

namespace ast {
  class GreaterExpression : public ast::BoolExpression, public std::enable_shared_from_this<GreaterExpression> {
  public:
    GreaterExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2);

    //bool eval() const override;


  private:
    std::shared_ptr<NumberExpression> first;
    std::shared_ptr<NumberExpression> second;
  };
}