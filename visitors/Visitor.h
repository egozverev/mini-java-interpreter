#pragma once

#include "forward_decl.h"

#include <memory>

class Visitor {
public:
  //virtual void Visit(std::shared_ptr<NumberExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<BoolExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<AddExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<SubstractExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<MulExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<ModExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<DivExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<IdentExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<AndExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<OrExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<LessExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<GreaterExpression> expression) = 0;
  //virtual void Visit(std::shared_ptr<EqualExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<PlainNumberExpression> expression) = 0;
  virtual void Visit(std::shared_ptr<Assignment> assignment) = 0;
  virtual void Visit(std::shared_ptr<StatementList> expression) = 0;
  virtual void Visit(std::shared_ptr<PrintStatement> expression) = 0;
  //virtual void Visit(std::shared_ptr<PlainIdent> expression) = 0;
  //virtual void Visit(std::shared_ptr<ClassDeclaration> expression) = 0;
  virtual void Visit(std::shared_ptr<ClassDeclarationList> expression) = 0;
  virtual void Visit(std::shared_ptr<MainClass> expression) = 0;
  virtual void Visit(std::shared_ptr<Program> program) = 0;
};