#include "MainClass.h"

MainClass::MainClass(std::shared_ptr<StatementList> statement_list) : statement_list_(std::move(statement_list)) {}

/*void MainClass::perform_body() const {
  statement_list_->execute();
}*/

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this->shared_from_this());
}

std::shared_ptr<StatementList> MainClass::GetStatementList() { return statement_list_; }