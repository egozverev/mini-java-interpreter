#include "IndexTable.h"

namespace calls {
  void IndexTable::Put(const Symbol& symbol, size_t index) {
    if (values_.find(symbol) == values_.end()) {
      throw std::runtime_error("Variable " + symbol.GetName() +  " not declared");
    }
    values_[symbol].pop();
    values_[symbol].push(index);
    symbols_.push(symbol);
  }

  size_t IndexTable::Get(const Symbol& symbol) {
    if (values_.find(symbol) == values_.end()) {
      throw std::runtime_error("Variable " + symbol.GetName() +  " not declared");
    }
    return values_[symbol].top();
  }

  bool IndexTable::HasSymbol(const Symbol &symbol) {
    return values_.find(symbol) != values_.end();
  }

  void IndexTable::CreateVariable(const Symbol& symbol, size_t index) {
    if (values_.find(symbol) == values_.end()) {
      values_[symbol] = std::stack<size_t>();
    }
    values_[symbol].push(index);
    symbols_.push(symbol);
  }

  void IndexTable::BeginScope() {
    symbols_.push(Symbol("{"));
  }

  void IndexTable::EndScope() {
    while (symbols_.top() != Symbol("{")) {
      Symbol symbol = symbols_.top();
      values_[symbol].pop();
      if (values_[symbol].empty()) {
        values_.erase(symbol);
      }
      symbols_.pop();
    }
    symbols_.pop();
  }
}