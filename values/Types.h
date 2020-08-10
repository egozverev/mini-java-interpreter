#pragma once
#include <string>

namespace ast{
  class Type{
  public:
    virtual std::string GetTypeName() = 0;
  };

  class Integer: public Type{
  public:
    std::string GetTypeName() override;
  };

  class Boolean: public Type{
  public:
    std::string GetTypeName() override;
  };

  class Void: public Type{
  public:
    std::string GetTypeName() override;
  };

  class UserType: public Type{
  public:
    std::string GetTypeName() override;
  };
}