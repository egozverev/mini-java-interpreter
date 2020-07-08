#include "StatementList.h"


void ast::StatementList::AddStatement(std::shared_ptr<ast::Statement> statement) {
  statements_.push_back(std::move(statement));
}

/*void StatementList::execute() const {
  for (auto it = statements_.end() - 1;
       it != statements_.begin() - 1; --it) {
    (*it)->execute();
  }
}*/

void ast::StatementList::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}