#pragma once

#include <string>
#include <memory>
#include <vector>

namespace ast {
  class Type {
  public:
    static std::shared_ptr<Type> BuildType(const std::string& name);
    virtual std::string GetTypeName() = 0;
  };

  class Integer : public Type {
  public:
    std::string GetTypeName() override;
  };

  class Boolean : public Type {
  public:
    std::string GetTypeName() override;
  };

  class Void : public Type {
  public:
    std::string GetTypeName() override;
  };

  class UserType : public Type {
  public:
    explicit UserType(std::string name);
    std::string GetTypeName() override;

  private:
    std::string type_name_;
  };

  class FunctionType : public Type {
  public:
    std::string GetTypeName() override;

    std::vector<std::shared_ptr<Type>> GetArgTypes();

    std::vector<std::string> GetArgNames();

  private:
    std::vector<std::shared_ptr<Type>> arg_types_;
    std::vector<std::string> arg_names_;
  };
}