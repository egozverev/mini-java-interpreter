#pragma once
#include <string>

namespace ast{
  class Type{
    virtual std::string GetType() = 0;
  };

  class Integer: Type{
    std::string GetType() override;
  };

  class Boolean: Type{
    std::string GetType() override;
  };

  class Void: Type{
    std::string GetType() override;
  };

  class UserType: Type{
    std::string GetType() override;
  };
}