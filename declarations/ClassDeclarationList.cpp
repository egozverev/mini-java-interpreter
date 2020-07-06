#include "ClassDeclarationList.h"

void ClassDeclarationList::AddDeclaration(std::shared_ptr<ClassDeclaration> declaration) {
  declarations_.push_back(std::move(declaration));
}

void ClassDeclarationList::Accept(Visitor& visitor) {
  visitor.Visit(this->shared_from_this());
}