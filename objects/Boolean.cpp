#include "Boolean.h"

Boolean::Boolean(bool value): value_(value) {}

int Boolean::ToInt() {
  return static_cast<int>(value_);
}
