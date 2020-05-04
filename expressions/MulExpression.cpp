#include "MulExpression.h"

MulExpression::MulExpression(
    NumberExpression *e1, NumberExpression *e2
): first(e1), second(e2) {}

int MulExpression::eval() const {
    return first->eval() * second->eval();
}