#include "Types.h"

namespace ast {
  std::string Integer::GetTypeName() {
    return "int";
  }

  std::string Void::GetTypeName() {
    return "void";
  }

  std::string Boolean::GetTypeName() {
    return "bool";
  }

  std::string UserType::GetTypeName() {
    return "user_type";
  }
}