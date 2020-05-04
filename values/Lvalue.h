#pragma once

#include <string>

class Lvalue {
public:
  virtual std::string GetId() const = 0;
};