#include "ThisExpression.h"

void ast::ThisExpression::Accept(Visitor &visitor) {
  visitor.Visit(this->shared_from_this());
}