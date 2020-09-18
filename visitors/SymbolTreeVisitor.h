#pragma once

#include <map>

#include "symbol_table/ScopeLayerTree.h"
#include "class_tree/ClassTree.h"

#include "Visitor.h"

class SymbolTreeVisitor: public Visitor {
public:
  SymbolTreeVisitor() = default;

  void Visit(std::shared_ptr<ast::ThisExpression> expression) override;

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

  void Visit(std::shared_ptr<ast::IfElseStatement> expression) override;

  void Visit(std::shared_ptr<ast::IfStatement> expression) override;

  void Visit(std::shared_ptr<ast::WhileStatement> expression) override;


  void Visit(std::shared_ptr<ast::ReturnStatement> expression) override;

  void Visit(std::shared_ptr<ast::StatementList> statement_list) override;

  void Visit(std::shared_ptr<ast::ClassDeclaration> declaration) override;

  void Visit(std::shared_ptr<ast::DeclarationList> decl_list) override;

  void Visit(std::shared_ptr<ast::ClassDeclarationList> decl_list) override;

  void Visit(std::shared_ptr<ast::MainClass> expression) override;

  void Visit(std::shared_ptr<ast::Program> program) override;

  void Visit(std::shared_ptr<ast::VariableDeclaration> declaration) override;

  void Visit(std::shared_ptr<ast::ClassVarDecl> expression) override;

  void Visit(std::shared_ptr<ast::Function> expression) override;

  void Visit(std::shared_ptr<ast::FunctionParameters> expression) override;

  void Visit(std::shared_ptr<ast::FunctionCall> expression) override;

  void Visit(std::shared_ptr<ast::ParamValueList> expression) override;

  ClassTree& GetClassTree();

private:
  ClassTree class_tree_;
  std::shared_ptr<ClassNode> current_node_;
  std::shared_ptr<ScopeLayer> current_layer_;
  std::string current_func_name_;
  bool is_new_scope_ = true; // true = create independent layer
};