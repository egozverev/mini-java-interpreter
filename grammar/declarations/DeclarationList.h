#pragma once

#include "grammar/functions/Function.h"
#include "grammar/values/VariableDeclaration.h"
#include "grammar/program_base/BaseElement.h"

#include <memory>
#include <vector>


namespace ast {
  class DeclarationList : BaseElement, public std::enable_shared_from_this<DeclarationList> {
  public:
    explicit DeclarationList() = default;

    void AddDeclaration(std::shared_ptr<Declaration> declaration);

    void Accept(Visitor &visitor) override;

    const std::vector<std::shared_ptr<Function> >& GetFunctions() const;

    const std::vector<std::shared_ptr<VariableDeclaration> >&  GetVarDecls() const;

  private:
    std::vector<std::shared_ptr<Function> > functions_;
    std::vector<std::shared_ptr<VariableDeclaration> > vardecls_;
  };
}