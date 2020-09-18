#pragma once

#include "Visitor.h"
#include "forward_decl.h"

#include <fstream>
#include <string>

class PrintVisitor : public Visitor {
public:
  explicit PrintVisitor(const std::string &filename);

  ~PrintVisitor();

  //void Visit(std::shared_ptr<ast::NumberExpression> expression) override;

  //void Visit(std::shared_ptr<ast::BoolExpression> expression) override;

  void Visit(std::shared_ptr<ast::AddExpression> expression) override;

  void Visit(std::shared_ptr<ast::SubstractExpression> expression) override;

  void Visit(std::shared_ptr<ast::MulExpression> expression) override;

  void Visit(std::shared_ptr<ast::ModExpression> expression) override;

  void Visit(std::shared_ptr<ast::DivExpression> expression) override;

  void Visit(std::shared_ptr<ast::IdentExpression> expression) override;

  //void Visit(std::shared_ptr<ast::AndExpression> expression) override;

  //void Visit(std::shared_ptr<ast::OrExpression> expression) override;

  //void Visit(std::shared_ptr<ast::LessExpression> expression) override;

  //void Visit(std::shared_ptr<ast::GreaterExpression> expression) override;

  //void Visit(std::shared_ptr<ast::EqualExpression> expression) override;

  void Visit(std::shared_ptr<ast::PlainNumberExpression> expression) override;

  void Visit(std::shared_ptr<ast::Assignment> assignment) override;

  void Visit(std::shared_ptr<ast::PrintStatement> expression) override;

  //void Visit(std::shared_ptr<ast::PlainIdent> expression) override;

  void Visit(std::shared_ptr<ast::StatementList> statemen_list) override;

  //void Visit(std::shared_ptr<ast::ClassDeclaration> expression) override;

  void Visit(std::shared_ptr<ast::ClassDeclarationList>expression) override;

  void Visit(std::shared_ptr<ast::MainClass> expression) override;

  void Visit(std::shared_ptr<ast::Program> program) override;

  void Visit(std::shared_ptr<ast::VariableDeclaration> declaration) override;


private:

  void PrintTabs();

  std::ofstream stream_;
  int num_tabs_ = 0;

};