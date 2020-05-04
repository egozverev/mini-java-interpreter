#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(NumberExpression *e1, NumberExpression *e2): first(e1), second(e2) {}

int SubstractExpression::eval() const {
    return first->eval() - second->eval();
}