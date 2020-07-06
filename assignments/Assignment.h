#pragma once

#include "expressions/Expression.h"
#include "statements/Statement.h"
#include "values/Lvalue.h"
#include <driver.hh>

#include <memory>
#include <string>



class Assignment : public Statement, public std::enable_shared_from_this<Assignment> {
public:
  Assignment(std::shared_ptr<Lvalue> lvalue, Driver& driver,  std::shared_ptr<Expression> expression);

  //void execute() const override ;

  std::shared_ptr<Lvalue> GetLvalue();

  std::shared_ptr<Expression> GetExpression();

  void Accept(Visitor *visitor) override;

private:
  std::shared_ptr<Lvalue> lvalue_;
  std::shared_ptr<Expression> expression_;
  Driver& driver_;
};