#pragma once

#include "NumberExpression.h"

#include <memory>

namespace ast {
  class DivExpression : public ast::Expression, public std::enable_shared_from_this<DivExpression> {
  public:
    DivExpression(std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2);

    void Accept(Visitor& visitor) override;

    std::shared_ptr<Expression> GetFirst();

    std::shared_ptr<Expression> GetSecond();

  private:
    std::shared_ptr<Expression> first;
    std::shared_ptr<Expression> second;
  };
}