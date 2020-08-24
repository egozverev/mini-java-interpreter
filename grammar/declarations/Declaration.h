#pragma once

#include <grammar/statements/Statement.h>

namespace ast {
  class Declaration : public Statement {
  public:
    virtual void Accept(Visitor &visitor) = 0;

    virtual ~Declaration() = default;

    virtual bool IsFunction();
  };
}
