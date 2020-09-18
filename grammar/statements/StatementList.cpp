#include "StatementList.h"


void ast::StatementList::AddStatement(std::shared_ptr<ast::Statement> statement) {
  statements_.push_back(std::move(statement));
}




void ast::StatementList::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}