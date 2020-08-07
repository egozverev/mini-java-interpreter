#pragma once
#include "Visitor.h"
#include "TemplateVisitor.h"
#include "symbol_table/ScopeLayer.h"
#include "objects/Integer.h"
#include "forward_decl.h"

#include <iostream>
#include <stack>
#include <map>
#include <memory>

class Interpreter : public TemplateVisitor<int>  { // not int btw
public:
  explicit Interpreter(std::shared_ptr<ScopeLayer> root);
  //void Visit(std::shared_ptr<ast::NumberExpression> expression) override;

  //void Visit(std::shared_ptr<ast::BoolExpression> expression) override;

  void Visit(std::shared_ptr<ast::AddExpression> expression) override;

  void Visit(std::shared_ptr<ast::SubstractExpression> expression) override;

  void Visit(std::shared_ptr<ast::MulExpression> expression) override;

  void Visit(std::shared_ptr<ast::ModExpression> expression) override;

  void Visit(std::shared_ptr<ast::DivExpression> expression) override;

  void Visit(std::shared_ptr<ast::IdentExpression> expression) override;

  void Visit(std::shared_ptr<ast::AndExpression> expression) override;

  void Visit(std::shared_ptr<ast::OrExpression> expression) override;

  void Visit(std::shared_ptr<ast::LessExpression> expression) override;

  void Visit(std::shared_ptr<ast::GreaterExpression> expression) override;

  void Visit(std::shared_ptr<ast::EqualExpression> expression) override;

  void Visit(std::shared_ptr<ast::PlainNumberExpression> expression) override;

  void Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) override;

  void Visit(std::shared_ptr<ast::Assignment> assignment) override;

  void Visit(std::shared_ptr<ast::PrintStatement> expression) override;

  //void Visit(std::shared_ptr<ast::PlainIdent> expression) override;

  void Visit(std::shared_ptr<ast::StatementList> statemen_list) override;

  //void Visit(std::shared_ptr<ast::ClassDeclaration> expression) override;

  void Visit(std::shared_ptr<ast::ClassDeclarationList>expression) override;

  void Visit(std::shared_ptr<ast::MainClass> expression) override;

  void Visit(std::shared_ptr<ast::Program> program) override;

  void Visit(std::shared_ptr<ast::VariableDeclaration> declaration) override;


  void Execute(std::shared_ptr<ast::Program> program);

private:
  std::shared_ptr<ScopeLayer> current_layer_;

  std::stack<int> offsets_;
};