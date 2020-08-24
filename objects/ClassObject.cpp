#include "ClassObject.h"

ClassObject::ClassObject(std::string name) : typename_(std::move(name)){
  type_ = ast::Type::BuildType(typename_);
}

std::string ClassObject::GetTypeName() {
  return typename_;
}

void ClassObject::AddVariable(const std::string &name, const Object &value) {
  if (HasVariable(name)) {
    throw std::runtime_error("Invalid class object");
  }
  variables_[name] = value;
}

bool ClassObject::HasVariable(const std::string &name) {
  return variables_.find(name) != variables_.end();
}

std::shared_ptr<Object> ClassObject::GetVariable(const std::string &name) {
  auto value = variables_.find(name);
  if (value == variables_.end()) {
    throw std::runtime_error("Invalid class object");
  }
  return std::make_shared<Object>(value->second);
}

bool ClassObject::IsClassObj() {
  return true;
}