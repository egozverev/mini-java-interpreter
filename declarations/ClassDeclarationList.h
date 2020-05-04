#pragma once

#include "ClassDeclaration.h"

#include <vector>

class ClassDeclarationList {
public:
  explicit ClassDeclarationList() = default;

  void AddDeclaration(ClassDeclaration *declaration);

private:
  std::vector<ClassDeclaration *> declarations_;
};