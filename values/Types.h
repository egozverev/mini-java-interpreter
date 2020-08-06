#pragma once
#include <string>

namespace ast{
  class Type{
  public:
    virtual std::string GetType() = 0;
  };

  class Integer: public Type{
  public:
    std::string GetType() override;
  };

  class Boolean: public Type{
  public:
    std::string GetType() override;
  };

  class Void: public Type{
  public:
    std::string GetType() override;
  };

  class UserType: public Type{
  public:
    std::string GetType() override;
  };
}