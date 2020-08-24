#pragma once

#include "Expression.h"

namespace ast {
  class ThisExpression : public Expression, public std::enable_shared_from_this<ThisExpression> {
  public:
    void Accept(Visitor &visitor) override;
  };
}