#pragma once

#include "Object.h"

class Boolean: public Object {
public:
  explicit Boolean(bool value);
  int ToInt() override;
private:
  bool value_;
};