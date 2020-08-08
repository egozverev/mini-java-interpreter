#pragma once

#include "values/Types.h"

#include <memory>

class Object {
public:
  ~Object() = default;

  int ToInt();

  bool ToBool();

  void SetValue(int value);

  //void SetType(std::unique_ptr<ast::Type> type);

private:
  int value_ = 0;
  //std::unique_ptr<ast::Type> type_;
};