#pragma once

//#include "Expression.h"

#include "program_base/BaseElement.h"

namespace ast {
  class BoolExpression: BaseElement, public std::enable_shared_from_this<BoolExpression> {
  public:
    //virtual bool eval() const = 0;
  };
}