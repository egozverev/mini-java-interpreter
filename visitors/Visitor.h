#pragma once

#include "forward_decl.h"
#include <memory>

class Visitor {
public:
  //virtual void Visit(std::shared_ptr<ast::NumberExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<ast::BoolExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::ThisExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::AddExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::SubstractExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::MulExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::ModExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::DivExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::IdentExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::AndExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::OrExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::LessExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::GreaterExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::EqualExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::PlainNumberExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::Assignment> assignment) = 0;
  virtual void Visit(std::shared_ptr<ast::StatementList> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::PrintStatement> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::IfElseStatement> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::IfStatement> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::WhileStatement> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::ReturnStatement> declaration) = 0;

  //virtual void Visit(std::shared_ptr<ast::PlainIdent> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::ClassDeclaration> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::DeclarationList> expression) = 0;

  virtual void Visit(std::shared_ptr<ast::ClassDeclarationList> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::MainClass> expression) = 0;
  virtual void Visit(std::shared_ptr<ast::Program> program) = 0;

  virtual void Visit(std::shared_ptr<ast::VariableDeclaration> declaration) = 0;
  virtual void Visit(std::shared_ptr<ast::ClassVarDecl> declaration) = 0;

  virtual void Visit(std::shared_ptr<ast::Function> declaration) = 0;
  virtual void Visit(std::shared_ptr<ast::FunctionParameters> declaration) = 0;

  virtual void Visit(std::shared_ptr<ast::ParamValueList> declaration) = 0;
  virtual void Visit(std::shared_ptr<ast::FunctionCall> declaration) = 0;

};