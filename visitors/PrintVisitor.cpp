#include "PrintVisitor.h"

#include "visitor_requirements.h"

#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) : stream_(filename) {
}

void SymbolTreeVisitor::Visit(PlainNumberExpression* expression) {
  PrintTabs();
  stream_ << "NumExpression " << expression->value << std::endl;
}

void SymbolTreeVisitor::Visit(AddExpression* expression) {
  PrintTabs();
  stream_ << "AddExpression is:" << std::endl;

  ++num_tabs_;
  expression->GetFirst()->Accept(this);
  expression->GetSecond()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
  PrintTabs();

  stream_ << "SubExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(this);
  expression->GetSecond()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(MulExpression* expression) {
  PrintTabs();

  stream_ << "MulExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(this);
  expression->GetSecond()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(ModExpression* expression) {
  PrintTabs();

  stream_ << "ModExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(this);
  expression->GetSecond()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
  PrintTabs();
  stream_ << "DivExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(this);
  expression->GetSecond()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
  PrintTabs();

  stream_ << "IdentExpression: " << expression->GetIdent() << std::endl;
}

void SymbolTreeVisitor::Visit(Assignment* assignment) {
  PrintTabs();
  stream_ << "Assignment: " << assignment->GetLvalue()->GetId() << std::endl;
  ++num_tabs_;
  assignment->GetExpression()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(PrintStatement* statement) {
  PrintTabs();
  stream_ << "PrintStatement: " << std::endl;
  ++num_tabs_;
  statement->GetExpression()->Accept(this);
  --num_tabs_;
}

void SymbolTreeVisitor::Visit(StatementList* statement_list) {
  PrintTabs();
  stream_ << "StatementList: " << std::endl;

  ++num_tabs_;
  for (auto it = statement_list->statements_.end() - 1;
       it != statement_list->statements_.begin() - 1; --it) {
    (*it)->Accept(this);
  }

  --num_tabs_;
}

/*void SymbolTreeVisitor::Visit(PlainIdent* expression) {
  PrintTabs();

  stream_ << "PlainIdent: " << expression->GetId() << std::endl;
}*/



void SymbolTreeVisitor::Visit(Program* program) {
  PrintTabs();
  stream_ << "Program:" << std::endl;

  ++num_tabs_;

  program->GetMainClass()->Accept(this);
  program->GetDeclList()->Accept(this);

  --num_tabs_;
}

void SymbolTreeVisitor::Visit(MainClass* main_class) {
  PrintTabs();
  stream_ << "MainClass:" << std::endl;

  ++num_tabs_;

  main_class->GetStatementList()->Accept(this);

  --num_tabs_;
}

void SymbolTreeVisitor::Visit(ClassDeclarationList* decl_list) {
  PrintTabs();
  stream_ << "Class DeclarationList:" << std::endl;

  ++num_tabs_;
  //yet nothing

  --num_tabs_;
}




void SymbolTreeVisitor::PrintTabs() {
  for (int i = 0; i < num_tabs_; ++i) {
    stream_ << '\t';
  }
}

SymbolTreeVisitor::~SymbolTreeVisitor() {
  stream_.close();
}