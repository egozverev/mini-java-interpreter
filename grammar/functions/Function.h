#pragma once

#include "grammar/program_base/BaseElement.h"
#include "grammar/functions/FunctionParameters.h"
#include "grammar/statements/StatementList.h"
#include "grammar/declarations/Declaration.h"

#include <memory>

namespace ast {
  class Function : public Declaration, public std::enable_shared_from_this<Function> {
  public:
    Function(std::string name, std::shared_ptr<Type> return_type,
        std::shared_ptr<FunctionParameters> params, std::shared_ptr<StatementList> statements);

    void Accept(Visitor& visitor) override;

    std::string GetName();

    std::shared_ptr<FunctionParameters> GetParams();

    std::shared_ptr<StatementList> GetStatements();

    bool IsFunction() override;

    size_t GetParamSize();

  private:
    std::string name_;
    std::shared_ptr<FunctionParameters> params_;
    std::shared_ptr<StatementList> statements_;
    std::shared_ptr<Type> return_type_;

  };


}

