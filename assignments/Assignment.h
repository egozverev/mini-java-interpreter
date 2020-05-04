#pragma once

#include "expressions/Expression.h"
#include "statements/Statement.h"
#include "values/Lvalue.h"
#include <driver.hh>
#include <string>

class Assignment : public Statement {
public:
  Assignment(Lvalue* lvalue, Driver& driver,  Expression *expression);

  void execute() const override ;

private:
  Lvalue* lvalue_;
  Expression *expression_;
  Driver& driver_;
};