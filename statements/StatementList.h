#pragma once

#include "statements/Statement.h"

#include <vector>

#include <memory>

class StatementList : BaseElement, public std::enable_shared_from_this<StatementList> {
public:
  void AddStatement(std::shared_ptr<Statement> statement);
  //void execute() const;

  void Accept(Visitor *visitor) override;

  std::vector<std::shared_ptr<Statement> > statements_;
};