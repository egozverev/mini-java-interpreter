#pragma once

//#include "Expression.h"

#include "BaseElement.h"

class BoolExpression: BaseElement, public std::enable_shared_from_this<BoolExpression> {
public:
  //virtual bool eval() const = 0;
};