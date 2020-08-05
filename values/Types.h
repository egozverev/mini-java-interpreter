#pragma once
#include <string>

namespace ast{
  class Type{
    virtual std::string GetType() = 0;
  };

  class Integer: public Type{
    std::string GetType() override;
  };

  class Boolean: public Type{
    std::string GetType() override;
  };

  class Void: public Type{
    std::string GetType() override;
  };

  class UserType: public Type{
    std::string GetType() override;
  };
}