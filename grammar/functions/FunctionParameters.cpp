#include "FunctionParameters.h"

namespace ast {
  FunctionParameters::FunctionParameters(std::string first_param, std::shared_ptr<ast::Type> first_type):
  parameters_{std::move(first_param)}, types_{std::move(first_type)} {}

  const std::vector<std::string>& FunctionParameters::GetParamList() {
    return parameters_;
  }

  const std::vector<std::shared_ptr<ast::Type> >& FunctionParameters::GetTypes() {
    return types_;
  }

  void FunctionParameters::AddParam(std::string param, std::shared_ptr<ast::Type> type) {
    parameters_.push_back(std::move(param));
    types_.push_back(std::move(type));
  }

  void FunctionParameters::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }
}
