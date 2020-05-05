#pragma once
#include "Visitor.h"

#include <map>

class Interpreter : public Visitor {
public:
  Interpreter();
  //void Visit(NumberExpression *expression) override;

  //void Visit(BoolExpression *expression) override;

  void Visit(AddExpression *expression) override;

  void Visit(SubstractExpression *expression) override;

  void Visit(MulExpression *expression) override;

  void Visit(ModExpression *expression) override;

  void Visit(DivExpression *expression) override;

  void Visit(IdentExpression *expression) override;

  //void Visit(AndExpression *expression) override;

  //void Visit(OrExpression *expression) override;

  //void Visit(LessExpression *expression) override;

  //void Visit(GreaterExpression *expression) override;

  //void Visit(EqualExpression *expression) override;

  void Visit(PlainNumberExpression *expression) override;

  void Visit(Assignment *assignment) override;

  void Visit(PrintStatement *expression) override;

  //void Visit(PlainIdent *expression) override; кажется, что он не нужен (пока что)

  void Visit(StatementList *statemen_list) override;

  //void Visit(ClassDeclaration *expression) override;

  void Visit(ClassDeclarationList *expression) override;

  void Visit(MainClass *expression) override;

  void Visit(Program *program) override;

  void Execute(Program *program);

private:
  void SetTosValue(int value);
  void UnsetTosValue();

  std::map<std::string, int> variables_;

  bool is_tos_expression_;
  int tos_value_;

};