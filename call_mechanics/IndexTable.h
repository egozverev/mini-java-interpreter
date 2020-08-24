#pragma once

#include <symbol_table/Symbol.h>

#include <stack>

namespace calls {
  class IndexTable {
  public:
    void Put(const Symbol& symbol, size_t index);

    void CreateVariable(const Symbol& symbol, size_t index);

    size_t Get(const Symbol& symbol);

    void BeginScope();

    void EndScope();

    bool HasSymbol(const Symbol& symbol);

  private:
    std::unordered_map<Symbol, std::stack<size_t>> values_; // symbol -> stack of indices
    std::stack<Symbol> symbols_;
  };
}