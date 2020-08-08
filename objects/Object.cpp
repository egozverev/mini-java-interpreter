#include "Object.h"

int Object::ToInt() {
    return value_;
}

bool Object::ToBool() {
  return static_cast<bool>(value_);
}

void Object::SetValue(int value){
  value_ = value;
}

//void Object::SetType(std::unique_ptr<ast::Type> type){
//  type_ = std::move(type);
//}
