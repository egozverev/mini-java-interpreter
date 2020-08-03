#include "VariableDeclaration.h"

namespace ast {
  VariableDeclaration::VariableDeclaration(std::string var_name, std::shared_ptr<Type> type) :
      var_name_(std::move(var_name)), var_type_(std::move(type)) {}

  void ast::VariableDeclaration::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  std::string ast::VariableDeclaration::GetName() {
    return var_name_;
  }
  std::shared_ptr<Type> ast::VariableDeclaration::GetType() {
    return var_type_;
  }
}