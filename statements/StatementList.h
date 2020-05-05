#pragma once

#include "statements/Statement.h"

#include <vector>

class StatementList: BaseElement {
public:
  void AddStatement(Statement* statement);
  //void execute() const;

  void Accept(Visitor *visitor) override;

  std::vector<Statement*> statements_;
};