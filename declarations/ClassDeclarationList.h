#pragma once

#include "ClassDeclaration.h"
#include "BaseElement.h"

#include <vector>

class ClassDeclarationList: BaseElement{
public:
  explicit ClassDeclarationList() = default;

  void AddDeclaration(ClassDeclaration *declaration);

  void Accept(Visitor *visitor) override;

private:
  std::vector<ClassDeclaration *> declarations_;
};