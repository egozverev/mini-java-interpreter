#pragma once

#include "NumberExpression.h"
#include "driver.hh"
#include <string>

class IdentExpression : public NumberExpression {
public:
  explicit IdentExpression(const std::string &ident, Driver& driver);

  int eval() const override;

private:
  std::string ident_;
  Driver& driver_;
};