#include "Object.h"

Object::Object(Types type) : type_(type) {}

int Object::ToInt() {
  return value_;
}

bool Object::ToBool() {
  return static_cast<bool>(value_);
}

void Object::SetValue(int value) {
  value_ = value;
}

void Object::SetType(Types type) {
  type_ = type;
}

void Object::SetType(const std::string &type) {
  if (type == "int") {
    SetType(INT);
  } else if (type == "bool") {
    SetType(BOOLEAN);
  } else if (type == "void") {
    SetType(VOID);
  } else if (type == "user_type") {
    SetType(USERTYPE);
  } else {
    throw std::runtime_error("Object SetType error");
  }
}

Types Object::GetType() {
  return type_;
}
