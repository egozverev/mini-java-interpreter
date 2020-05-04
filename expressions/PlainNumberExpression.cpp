#include "PlainNumberExpression.h"

PlainNumberExpression::PlainNumberExpression(int value) {
  value_ = value;
}

int PlainNumberExpression::eval() const {
  return value_;
}