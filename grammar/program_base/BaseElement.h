#pragma once

#include "visitors/Visitor.h"


namespace ast {
  class BaseElement {
  public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~BaseElement() = default;
  };
}