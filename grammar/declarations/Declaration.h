#pragma once

#include <grammar/statements/Statement.h>

namespace ast {
  class Declaration : public Statement {
  public:
    virtual bool IsFunction() = 0;
  };
}
