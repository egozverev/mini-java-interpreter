#include "ReturnStatement.h"

namespace ast {
  ReturnStatement::ReturnStatement(std::shared_ptr<Expression> expr): expr_(std::move(expr)) {}
  std::shared_ptr<Expression> ReturnStatement::GetExpr() {
    return expr_;
  }
  void ReturnStatement::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }
}