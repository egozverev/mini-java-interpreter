#include "PrintVisitor.h"

#include "visitor_requirements.h"
#include "forward_decl.h"

#include <iostream>

PrintVisitor::PrintVisitor(const std::string &filename) : stream_(filename) {
}

void PrintVisitor::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {
  PrintTabs();
  stream_ << "NumExpression " << expression->value << std::endl;
}

void PrintVisitor::Visit(std::shared_ptr<ast::AddExpression> expression) {
  PrintTabs();
  stream_ << "AddExpression is:" << std::endl;

  ++num_tabs_;
  expression->GetFirst()->Accept(*this);
  expression->GetSecond()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::SubstractExpression> expression) {
  PrintTabs();

  stream_ << "SubExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(*this);
  expression->GetSecond()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::MulExpression> expression) {
  PrintTabs();

  stream_ << "MulExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(*this);
  expression->GetSecond()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::ModExpression> expression) {
  PrintTabs();

  stream_ << "ModExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(*this);
  expression->GetSecond()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::DivExpression> expression) {
  PrintTabs();
  stream_ << "DivExpression: " << std::endl;
  ++num_tabs_;
  expression->GetFirst()->Accept(*this);
  expression->GetSecond()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::IdentExpression> expression) {
  PrintTabs();

  stream_ << "IdentExpression: " << expression->GetIdent() << std::endl;
}

void PrintVisitor::Visit(std::shared_ptr<ast::Assignment> assignment) {
  PrintTabs();
  stream_ << "Assignment: " << assignment->GetLvalue()->GetId() << std::endl;
  ++num_tabs_;
  assignment->GetExpression()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::PrintStatement> statement) {
  PrintTabs();
  stream_ << "PrintStatement: " << std::endl;
  ++num_tabs_;
  statement->GetExpression()->Accept(*this);
  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  PrintTabs();
  stream_ << "StatementList: " << std::endl;

  ++num_tabs_;
  for (auto it = statement_list->statements_.end() - 1;
       it != statement_list->statements_.begin() - 1; --it) {
    (*it)->Accept(*this);
  }

  --num_tabs_;
}


void PrintVisitor::Visit(std::shared_ptr<ast::Program> program) {
  PrintTabs();
  stream_ << "Program:" << std::endl;

  ++num_tabs_;

  program->GetMainClass()->Accept(*this);
  program->GetDeclList()->Accept(*this);

  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::MainClass> main_class) {
  PrintTabs();
  stream_ << "MainClass:" << std::endl;

  ++num_tabs_;

  main_class->GetStatementList()->Accept(*this);

  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::ClassDeclarationList> decl_list) {
  PrintTabs();
  stream_ << "Class DeclarationList:" << std::endl;

  ++num_tabs_;
  //yet nothing

  --num_tabs_;
}

void PrintVisitor::Visit(std::shared_ptr<ast::VariableDeclaration> declaration) {
  PrintTabs();
  stream_ << "Variable DeclarationList:" << std::endl;
}


void PrintVisitor::PrintTabs() {
  for (int i = 0; i < num_tabs_; ++i) {
    stream_ << '\t';
  }
}

PrintVisitor::~PrintVisitor() {
  stream_.close();
}