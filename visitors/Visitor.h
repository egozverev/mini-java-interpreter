#pragma once

#include "forward_decl.h"

class Visitor {
public:
  //virtual void Visit(NumberExpression* expression) = 0;
  //virtual void Visit(BoolExpression* expression) = 0;
  virtual void Visit(AddExpression* expression) = 0;
  virtual void Visit(SubstractExpression* expression) = 0;
  virtual void Visit(MulExpression* expression) = 0;
  virtual void Visit(ModExpression* expression) = 0;
  virtual void Visit(DivExpression* expression) = 0;
  virtual void Visit(IdentExpression* expression) = 0;
  //virtual void Visit(AndExpression* expression) = 0;
  //virtual void Visit(OrExpression* expression) = 0;
  //virtual void Visit(LessExpression* expression) = 0;
  //virtual void Visit(GreaterExpression* expression) = 0;
  //virtual void Visit(EqualExpression* expression) = 0;
  virtual void Visit(PlainNumberExpression* expression) = 0;
  virtual void Visit(Assignment* assignment) = 0;
  virtual void Visit(StatementList* expression) = 0;
  virtual void Visit(PrintStatement* expression) = 0;
  //virtual void Visit(PlainIdent* expression) = 0;
  //virtual void Visit(ClassDeclaration* expression) = 0;
  virtual void Visit(ClassDeclarationList* expression) = 0;
  virtual void Visit(MainClass* expression) = 0;
  virtual void Visit(Program* program) = 0;
};