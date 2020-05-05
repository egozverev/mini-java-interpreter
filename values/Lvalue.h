#pragma once

#include <string>

#include "BaseElement.h"

class Lvalue {
public:
  virtual std::string GetId() const = 0;
};