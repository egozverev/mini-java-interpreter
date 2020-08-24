#pragma once

#include "Expression.h"

namespace ast {
  class PlainBooleanExpression : public ast::Expression, public std::enable_shared_from_this<PlainBooleanExpression> {
  public:
    explicit PlainBooleanExpression(bool value);

    void Accept(Visitor& visitor) override;

    bool value;

  };
}