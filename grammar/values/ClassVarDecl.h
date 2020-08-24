#pragma once

#include <grammar/expressions/Expression.h>

#include <memory>

namespace ast {
  class ClassVarDecl : public Expression, public std::enable_shared_from_this<ClassVarDecl> {
  public:
    explicit ClassVarDecl(std::string name);

    void Accept(Visitor &visitor) override;

    std::string GetName();

  private:
    std::string class_name_;
  };

}