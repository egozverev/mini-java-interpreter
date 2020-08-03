#include "Types.h"

namespace ast {
  std::string Integer::GetType() {
    return "int";
  }

  std::string Void::GetType() {
    return "void";
  }

  std::string Boolean::GetType() {
    return "bool";
  }

  std::string UserType::GetType() {
    return "user_type";
  }
}