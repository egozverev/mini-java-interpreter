#pragma once

#include "Expression.h"
#include "grammar/driver.hh"
#include <string>

namespace ast {
  class IdentExpression : public ast::Expression, public std::enable_shared_from_this<IdentExpression> {
  public:
    explicit IdentExpression(const std::string &ident, Driver& driver);

    //int eval() const override;

    void Accept(Visitor& visitor) override;

    std::string GetIdent();

  private:
    std::string ident_;
    Driver& driver_;
  };
}