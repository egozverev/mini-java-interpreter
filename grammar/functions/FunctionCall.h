#pragma once

#include "grammar/statements/Statement.h"
#include "ParamValuesList.h"
namespace ast {
class FunctionCall: public Statement, public std::enable_shared_from_this<FunctionCall> {
public:
  FunctionCall(std::shared_ptr<Expression> class_entity, std::string name, std::shared_ptr<ParamValueList> param_values);
  void Accept(Visitor& visitor);

  std::shared_ptr<Expression> GetClassEntity();
  std::shared_ptr<ParamValueList> GetParamValues();
  std::string GetName();
private:
  std::string func_name_;
  std::shared_ptr<Expression> class_entity_;
  std::shared_ptr<ParamValueList> param_values_;
};
}