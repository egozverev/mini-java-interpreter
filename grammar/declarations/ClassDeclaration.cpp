#include "ClassDeclaration.h"

namespace ast {
  ClassDeclaration::ClassDeclaration(std::string class_name, std::string parent_name,
                                     std::shared_ptr<DeclarationList> decl_list) :
      class_name_(std::move(class_name)), parent_name_(std::move(parent_name)),
      decl_list_(std::move(decl_list)) {}

  void ClassDeclaration::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  std::string ClassDeclaration::GetName() { return class_name_; }

  std::string ClassDeclaration::GetParentName() { return parent_name_; }

  std::shared_ptr<DeclarationList> ClassDeclaration::GetDeclList() { return decl_list_; }

}