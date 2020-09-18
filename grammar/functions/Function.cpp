#include "Function.h"

namespace ast {
  Function::Function(std::string name, std::shared_ptr<Type> return_type,
                     std::shared_ptr<FunctionParameters> params,
                     std::shared_ptr<StatementList> statements) : name_(std::move(name)),
                                                                  params_(std::move(params)),
                                                                  statements_(std::move(statements)),
                                                                  return_type_(std::move(return_type)) {}

  void Function::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  std::string Function::GetName() { return name_; }

  std::shared_ptr<FunctionParameters> Function::GetParams() { return params_; }

  std::shared_ptr<StatementList> Function::GetStatements() { return statements_; }

  bool Function::IsFunction() {
    return true;
  }

  size_t Function::GetParamSize() {
    return GetParams()->GetParamList().size();
  }
}