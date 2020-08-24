#include "PlainBooleanExpression.h"

ast::PlainBooleanExpression::PlainBooleanExpression(bool val): value(val) {
}

void ast::PlainBooleanExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}