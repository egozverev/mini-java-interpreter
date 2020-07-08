#pragma once

#include "BoolExpression.h"
#include "NumberExpression.h"

#include <memory>

namespace ast {
  class LessExpression : public ast::BoolExpression, public std::enable_shared_from_this<LessExpression>{
  public:
    LessExpression(std::shared_ptr<NumberExpression> e1, std::shared_ptr<NumberExpression> e2);

    //bool eval() const override;

  private:
    std::shared_ptr<NumberExpression> first;
    std::shared_ptr<NumberExpression> second;
  };
}