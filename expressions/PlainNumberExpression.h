#pragma once

#include "Expression.h"

namespace ast {
  class PlainNumberExpression : public ast::Expression, public std::enable_shared_from_this<PlainNumberExpression> {
  public:
    explicit PlainNumberExpression(int value);

    void Accept(Visitor& visitor) override;

    int value;

  };
}