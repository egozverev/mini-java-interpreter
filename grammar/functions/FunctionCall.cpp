#include "FunctionCall.h"

namespace ast {
  FunctionCall::FunctionCall(std::shared_ptr<Expression> class_entity, std::string name,
                             std::shared_ptr<ParamValueList> param_values) :
      class_entity_(std::move(class_entity)), param_values_(std::move(param_values)), func_name_(std::move(name)) {}

  std::shared_ptr<Expression> FunctionCall::GetClassEntity() {
    return class_entity_;
  }

  std::shared_ptr<ParamValueList> FunctionCall::GetParamValues() {
    return param_values_;
  }

  void FunctionCall::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  std::string FunctionCall::GetName() {
    return func_name_;
  }

}