#pragma once

#include "Visitor.h"
#include "TemplateVisitor.h"
#include "symbol_table/ScopeLayer.h"
#include "grammar/values/Types.h"
#include "objects/ClassObject.h"
#include "forward_decl.h"
#include "class_tree/ClassTree.h"
#include "call_mechanics/Frame.h"
#include "call_mechanics/IndexTable.h"

#include <iostream>
#include <stack>
#include <map>
#include <memory>


class FunctionCallVisitor : public TemplateVisitor<std::shared_ptr<Object>> {
public:
  explicit FunctionCallVisitor(std::shared_ptr<ClassObject> class_obj, const std::string &func_name);

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

  void Visit(std::shared_ptr<ast::ClassVarDecl> declaration) override;

  void Visit(std::shared_ptr<ast::Function> function) override;

  void Visit(std::shared_ptr<ast::FunctionParameters> params) override;

  void Visit(std::shared_ptr<ast::FunctionCall> func_call) override;

  void Visit(std::shared_ptr<ast::ParamValueList> params) override;

  void SetParams(const std::vector<Object>& params);

  void SetTosValue(const int value);

  void SetTosValue(const bool value);

  void SetTosValue(const Object &value);

  calls::Frame& GetFrame();

  static void InitClassTree(const ClassTree &class_tree);

private:

  inline static ClassTree class_tree_;

  std::shared_ptr<ClassObject> class_object_;

  std::shared_ptr<ScopeLayer> current_layer_;

  std::stack<int> offsets_;

  calls::Frame frame_;

  calls::IndexTable index_table_;

  bool is_returned_ {false};

  bool is_new_scope_ = true;

};