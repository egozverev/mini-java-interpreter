#pragma once

#include "grammar/program_base/BaseElement.h"
#include "DeclarationList.h"

namespace ast {
  class ClassDeclaration : public BaseElement, public std::enable_shared_from_this<ClassDeclaration> {
  public:
    ClassDeclaration(std::string class_name, std::string parent_name, std::shared_ptr<DeclarationList> decl_list);

    std::string GetName();
    std::string GetParentName();
    std::shared_ptr<DeclarationList> GetDeclList();

    void Accept(Visitor& visitor) override;

  private:
    std::string class_name_;
    std::string parent_name_ = "";
    std::shared_ptr<DeclarationList> decl_list_;
  };
}