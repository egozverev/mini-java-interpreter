#include "ClassVarDecl.h"

namespace ast {
  ClassVarDecl::ClassVarDecl(std::string name): class_name_(std::move(name)) {}

  std::string ClassVarDecl::GetName() {
    return class_name_;
  }

  void ClassVarDecl::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }
}