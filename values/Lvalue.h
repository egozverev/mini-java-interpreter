#pragma once

#include <string>

#include "program_base/BaseElement.h"

namespace ast {
  class Lvalue {
  public:
    virtual std::string GetId() const = 0;
  };
}