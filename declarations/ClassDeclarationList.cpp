#include "ClassDeclarationList.h"

void ClassDeclarationList::AddDeclaration(ClassDeclaration *declaration) {
  declarations_.push_back(declaration);
}