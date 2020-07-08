#pragma once
#include "Visitor.h"
#include "forward_decl.h"

#include <map>

class Interpreter : public Visitor {
public:
  Interpreter();
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

  void Execute(std::shared_ptr<ast::Program> program);

private:
  void SetTosValue(int value);
  void UnsetTosValue();

  std::map<std::string, int> variables_;

  bool is_tos_expression_;
  int tos_value_;

};