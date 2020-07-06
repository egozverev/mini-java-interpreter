#pragma once
#include "Visitor.h"

#include <map>

class Interpreter : public Visitor {
public:
  Interpreter();
  //void Visit(std::shared_ptr<NumberExpression> expression) override;

  //void Visit(std::shared_ptr<BoolExpression> expression) override;

  void Visit(std::shared_ptr<AddExpression> expression) override;

  void Visit(std::shared_ptr<SubstractExpression> expression) override;

  void Visit(std::shared_ptr<MulExpression> expression) override;

  void Visit(std::shared_ptr<ModExpression> expression) override;

  void Visit(std::shared_ptr<DivExpression> expression) override;

  void Visit(std::shared_ptr<IdentExpression> expression) override;

  //void Visit(std::shared_ptr<AndExpression> expression) override;

  //void Visit(std::shared_ptr<OrExpression> expression) override;

  //void Visit(std::shared_ptr<LessExpression> expression) override;

  //void Visit(std::shared_ptr<GreaterExpression> expression) override;

  //void Visit(std::shared_ptr<EqualExpression> expression) override;

  void Visit(std::shared_ptr<PlainNumberExpression> expression) override;

  void Visit(std::shared_ptr<Assignment> assignment) override;

  void Visit(std::shared_ptr<PrintStatement> expression) override;

  //void Visit(std::shared_ptr<PlainIdent> expression) override;

  void Visit(std::shared_ptr<StatementList> statemen_list) override;

  //void Visit(std::shared_ptr<ClassDeclaration> expression) override;

  void Visit(std::shared_ptr<ClassDeclarationList>expression) override;

  void Visit(std::shared_ptr<MainClass> expression) override;

  void Visit(std::shared_ptr<Program> program) override;

  void Execute(std::shared_ptr<Program> program);

private:
  void SetTosValue(int value);
  void UnsetTosValue();

  std::map<std::string, int> variables_;

  bool is_tos_expression_;
  int tos_value_;

};