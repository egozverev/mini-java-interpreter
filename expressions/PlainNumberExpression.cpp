#include "PlainNumberExpression.h"

ast::PlainNumberExpression::PlainNumberExpression(int val): value(val) {
}

void ast::PlainNumberExpression::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}