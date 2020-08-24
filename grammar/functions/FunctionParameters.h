#pragma once

#include "grammar/program_base/BaseElement.h"

#include "grammar/values/Types.h"

#include <memory>

#include <vector>


namespace ast {
  class FunctionParameters : public BaseElement, public std::enable_shared_from_this<FunctionParameters> {
  public:
    FunctionParameters() = default;

    explicit FunctionParameters(std::string first_param, std::shared_ptr<ast::Type> first_type);

    const std::vector<std::string>& GetParamList();

    const std::vector<std::shared_ptr<ast::Type>>& GetTypes();

    void Accept(Visitor& visitor) override;

    void AddParam(std::string param, std::shared_ptr<ast::Type> type);

  private:
    std::vector<std::string> parameters_;
    std::vector<std::shared_ptr<ast::Type>> types_;
  };
}