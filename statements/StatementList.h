#pragma once

#include "statements/Statement.h"
#include "program_base/BaseElement.h"

#include <vector>

#include <memory>

namespace ast {
  class StatementList : ast::BaseElement, public std::enable_shared_from_this<StatementList> {
  public:
    void AddStatement(std::shared_ptr<Statement> statement);
    //void execute() const;

    void Accept(Visitor& visitor) override;

    std::vector<std::shared_ptr<Statement> > statements_;
  };
}