#include "Assignment.h"

Assignment::Assignment(
    Lvalue* lvalue,
    Driver& driver,
    Expression *expression
) : lvalue_(lvalue), expression_(expression), driver_(driver) {}

void Assignment::execute() const {
  driver_.variables[lvalue_->GetId()] = expression_ -> eval();
}