#include "PlainNumberExpression.h"

PlainNumberExpression::PlainNumberExpression(int val): value(val) {
}

/*int PlainNumberExpression::eval() const {
  return value;
}*/

void PlainNumberExpression::Accept(Visitor* visitor) {
  visitor->Visit(this->shared_from_this());
}