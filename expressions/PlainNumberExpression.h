#pragma once

#include "NumberExpression.h"

namespace ast {
  class PlainNumberExpression : public ast::NumberExpression, public std::enable_shared_from_this<PlainNumberExpression> {
  public:
    explicit PlainNumberExpression(int value);

    //int eval() const override;

    void Accept(Visitor& visitor) override;

    int value;

  };
}