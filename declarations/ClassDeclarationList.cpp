#include "ClassDeclarationList.h"

void ClassDeclarationList::AddDeclaration(ClassDeclaration *declaration) {
  declarations_.push_back(declaration);
}

void ClassDeclarationList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}