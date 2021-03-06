#pragma once

#include "Visitor.h"
#include "grammar/program_base/BaseElement.h"

template<typename T>
class TemplateVisitor : public Visitor {
public:
  T Accept(std::shared_ptr<ast::BaseElement> element){
    element->Accept(*this);
    return tos_value_;
  }

protected:
  T tos_value_;

};