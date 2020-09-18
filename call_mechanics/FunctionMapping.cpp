#include "FunctionMapping.h"

namespace calls {
  FunctionMapping &FunctionMapping::GetInstance() {
    static FunctionMapping mapping;
    return mapping;
  }
  void FunctionMapping::Set(Symbol symbol, std::shared_ptr<ast::Function> function) {
    functions_[std::move(symbol)] = std::move(function);
  }
  std::shared_ptr<ast::Function> FunctionMapping::Get(const Symbol &symbol) const {

  }
}