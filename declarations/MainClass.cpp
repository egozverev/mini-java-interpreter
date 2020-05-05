#include "MainClass.h"

MainClass::MainClass(StatementList *statement_list) : statement_list_(statement_list) {}

/*void MainClass::perform_body() const {
  statement_list_->execute();
}*/

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

StatementList *MainClass::GetStatementList() { return statement_list_; }