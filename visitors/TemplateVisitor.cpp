#include "TemplateVisitor.h"

template<typename T>
T TemplateVisitor<T>::Accept(std::shared_ptr<ast::BaseElement> element) {
  element->Accept(*this);
  return tos_value_;
}

template int TemplateVisitor<int>::Accept(std::shared_ptr<ast::BaseElement> element);
// explicit instantiation for T == int