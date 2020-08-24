#include "Types.h"

namespace ast {
  std::shared_ptr<Type> Type::BuildType(const std::string& name) {
    if (name == "int") {
      return std::make_shared<Integer>();
    } else if (name == "bool") {
      return std::make_shared<Boolean>();
    } else if (name == "void") {
      return std::make_shared<Void>();
    } else {
      return std::make_shared<UserType>(name);
    }
  }

  std::string Integer::GetTypeName() {
    return "int";
  }

  std::string Void::GetTypeName() {
    return "void";
  }

  std::string Boolean::GetTypeName() {
    return "bool";
  }

  std::string UserType::GetTypeName() {
    return type_name_;
  }

  std::string FunctionType::GetTypeName() {
    return "function";
  }

  std::vector<std::string> FunctionType::GetArgNames() {
    return arg_names_;
  }

  std::vector<std::shared_ptr<Type> > FunctionType::GetArgTypes() {
    return arg_types_;
  }

  UserType::UserType(std::string name): type_name_(std::move(name)) {}

}