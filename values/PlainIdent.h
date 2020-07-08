#pragma once

#include "Lvalue.h"

#include <string>

namespace ast {
  class PlainIdent : public ast::Lvalue {
  public:
    PlainIdent(const std::string &ident);

    std::string GetId() const override;

    //void Accept(Visitor *visitor) override;


  private:
    std::string ident_;
  };
}