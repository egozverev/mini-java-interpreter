#pragma once

#include "ClassDeclaration.h"
#include "grammar/program_base/BaseElement.h"

#include <memory>
#include <vector>


namespace ast {
  class ClassDeclarationList : BaseElement, public std::enable_shared_from_this<ClassDeclarationList> {
  public:
    explicit ClassDeclarationList() = default;

    void AddDeclaration(std::shared_ptr<ClassDeclaration> declaration);

    void Accept(Visitor& visitor) override;

    std::vector<std::shared_ptr<ClassDeclaration> > GetDeclarations();

  private:
    std::vector<std::shared_ptr<ClassDeclaration> > declarations_;
  };
}