#pragma once

#include "BoolExpression.h"

#include <memory>

namespace ast {
  class AndExpression : public ast::BoolExpression, public std::enable_shared_from_this<AndExpression> {
  public:
    AndExpression(std::shared_ptr<BoolExpression> e1, std::shared_ptr<BoolExpression> e2);

  private:
    std::shared_ptr<BoolExpression> first;
    std::shared_ptr<BoolExpression> second;
  };
}