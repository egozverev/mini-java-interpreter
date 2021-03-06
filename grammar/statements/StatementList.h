#pragma once

#include "Statement.h"
#include "grammar/program_base/BaseElement.h"

#include <vector>

#include <memory>

namespace ast {
  class StatementList : public ast::Statement, public std::enable_shared_from_this<StatementList> {
  public:
    void AddStatement(std::shared_ptr<Statement> statement);

    void Accept(Visitor &visitor) override;

    std::vector<std::shared_ptr<Statement> > statements_;
  };
}