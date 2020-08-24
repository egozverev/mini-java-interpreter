#pragma once
#include <string>
#include "grammar/statements/Statement.h"
#include "grammar/declarations/Declaration.h"
#include "Types.h"

namespace ast {
  class VariableDeclaration : public ast::Declaration, public std::enable_shared_from_this<VariableDeclaration> {
  public:
    explicit VariableDeclaration(std::string var_name, std::shared_ptr<Type> type);

    void Accept(Visitor &visitor) override;

    std::string GetName();

    std::shared_ptr<ast::Type> GetType();

    bool IsFunction() override;

  private:

    const std::string var_name_;

    std::shared_ptr<ast::Type> var_type_;
  };
}