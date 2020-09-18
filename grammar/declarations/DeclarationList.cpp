#include "DeclarationList.h"

namespace ast{
  void DeclarationList::AddDeclaration(std::shared_ptr<Declaration> declaration) {
    if (declaration->IsFunction()){
      functions_.push_back(std::move(std::dynamic_pointer_cast<Function>(declaration)));
    }
    else {
      vardecls_.push_back(std::dynamic_pointer_cast<VariableDeclaration>(declaration));
    }
  }
  void DeclarationList::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  const std::vector<std::shared_ptr<Function> >& DeclarationList::GetFunctions() const {
    return functions_;
  }

  const std::vector<std::shared_ptr<VariableDeclaration> >& DeclarationList::GetVarDecls() const {
    return vardecls_;
  }
}