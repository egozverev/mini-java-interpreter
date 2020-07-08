#include "LessExpression.h"

ast::LessExpression::LessExpression(std::shared_ptr<ast::NumberExpression> e1, std::shared_ptr<ast::NumberExpression> e2) :
  first(std::move(e1)), second(std::move(e2)) {}

/*bool LessExpression::eval() const {
  return first->eval() < second->eval();
}*/