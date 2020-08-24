#pragma once

#include <symbol_table/Symbol.h>
#include <unordered_map>
#include <grammar/functions/Function.h>
namespace calls {
  class FunctionMapping {
  public:
    static FunctionMapping& GetInstance();
    void Set(Symbol symbol, std::shared_ptr<ast::Function> function);
    std::shared_ptr<ast::Function> Get(const Symbol& symbol) const;
    FunctionMapping(const FunctionMapping& other) = delete;
    FunctionMapping& operator= (const FunctionMapping&) = delete;
  private:
    FunctionMapping() = default; // create with GetInstance
    ~FunctionMapping() = default;

    std::unordered_map<Symbol, std::shared_ptr<ast::Function>> functions_;
  };
}
