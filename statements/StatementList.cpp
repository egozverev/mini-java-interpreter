#include "StatementList.h"


void StatementList::AddStatement(Statement *statement) {
  statements_.push_back(statement);
}

void StatementList::execute() const {
  for (auto it = statements_.end() - 1;
       it != statements_.begin() - 1; --it) {
    (*it)->execute();
  }
}