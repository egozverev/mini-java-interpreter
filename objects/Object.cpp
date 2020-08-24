#include "Object.h"

Object::Object(std::shared_ptr<ast::Type> type) : type_(std::move(type)) {}

int Object::ToInt() {
  return value_;
}

bool Object::ToBool() {
  return static_cast<bool>(value_);
}

void Object::SetValue(int value) {
  value_ = value;
}

void Object::SetType(std::shared_ptr<ast::Type> type) {
  type_ = std::move(type);
}

void Object::SetType(const std::string &type) {
  type_ = ast::Type::BuildType(type);
}

std::shared_ptr<ast::Type> Object::GetType() {
  return type_;
}

bool Object::IsClassObj() {
  return false;
}