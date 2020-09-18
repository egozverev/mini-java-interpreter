#include "MainClass.h"

ast::MainClass::MainClass(std::shared_ptr<ast::StatementList> statement_list) : statement_list_(std::move(statement_list)) {}


void ast::MainClass::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());

}

std::shared_ptr<ast::StatementList> ast::MainClass::GetStatementList() { return statement_list_; }