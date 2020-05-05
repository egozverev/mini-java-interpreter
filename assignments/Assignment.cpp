#include "Assignment.h"

Assignment::Assignment(
    Lvalue *lvalue,
    Driver &driver,
    Expression *expression
) : lvalue_(lvalue), expression_(expression), driver_(driver) {}

/*void Assignment::execute() const {
  driver_.variables[lvalue_->GetId()] = expression_->eval();
}*/

Lvalue *Assignment::GetLvalue() { return lvalue_; }

Expression *Assignment::GetExpression() { return expression_; }

void Assignment::Accept(Visitor *visitor) {
  visitor->Visit(this);
}