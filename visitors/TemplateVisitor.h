#pragma once

#include "Visitor.h"
#include "program_base/BaseElement.h"

template<typename T>
class TemplateVisitor : public Visitor {
public:
  T Accept(std::shared_ptr<ast::BaseElement> element);

protected:
  T tos_value_;

};