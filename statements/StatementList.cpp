#include "StatementList.h"


void StatementList::AddStatement(Statement *statement) {
  statements_.push_back(statement);
}

void StatementList::execute() const {
  for (Statement *statement: statements_) {
    statement->execute();
  }
}