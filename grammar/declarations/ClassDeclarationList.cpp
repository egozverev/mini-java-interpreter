#include "ClassDeclarationList.h"
#include "ClassDeclaration.h"

void ast::ClassDeclarationList::AddDeclaration(std::shared_ptr<ast::ClassDeclaration> declaration) {
  declarations_.push_back(std::move(declaration));
}

void ast::ClassDeclarationList::Accept(Visitor &visitor) {
  visitor.Visit(this->shared_from_this());
}

std::vector<std::shared_ptr<ast::ClassDeclaration> > ast::ClassDeclarationList::GetDeclarations() {
  return declarations_;
}