#pragma once

#include "Lvalue.h"

#include <string>

class PlainIdent : public Lvalue {
public:
  PlainIdent(const std::string &ident);

  std::string GetId() const override;

private:
  std::string ident_;
};