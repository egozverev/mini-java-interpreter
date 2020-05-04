#pragma once

#include "statements/Statement.h"

#include <vector>

class StatementList {
public:
  void AddStatement(Statement* statement);
  void execute() const;
private:
  std::vector<Statement*> statements_;
};