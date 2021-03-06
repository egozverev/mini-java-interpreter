#include "ScopeLayer.h"


#include <iostream>


void ScopeLayer::DeclareVariable(const Symbol &symbol, const std::string& type) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable has been declared");
  }

  values_[symbol] = ast::Type::BuildType(type);
  offsets_[symbol] = symbols_.size();
  symbols_.push_back(symbol);
}

void ScopeLayer::DeclareVariable(const Symbol &symbol, std::shared_ptr<ast::Type> type){
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable has been declared");
  }
  values_[symbol] = std::move(type);
  offsets_[symbol] = symbols_.size();
  symbols_.push_back(symbol);
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetDeclarationLevel(const Symbol &symbol) {
  std::shared_ptr<ScopeLayer> current_layer = shared_from_this();
  while (current_layer != nullptr && !current_layer->Has(symbol)) {
    current_layer = current_layer->GetParent();
  }
  return std::move(current_layer);
}


void ScopeLayer::Put(const Symbol &symbol, std::shared_ptr<ast::Type> value) {
  std::shared_ptr<ScopeLayer> current_layer = std::move(GetDeclarationLevel(symbol));
  if (current_layer != nullptr) {
    current_layer->values_.find(symbol)->second = std::move(value);
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

bool ScopeLayer::Has(const Symbol &symbol) {
  return values_.find(symbol) != values_.end();
}


std::shared_ptr<ast::Type> ScopeLayer::GetType(const Symbol &symbol) {
  std::shared_ptr<ScopeLayer> current_layer = std::move(GetDeclarationLevel(symbol));
  if (current_layer != nullptr) {
    return current_layer->values_.find(symbol)->second;
  } else {
    return nullptr;
  }
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetChild(size_t index) {
  return children_[index];
}

void ScopeLayer::AddChild(std::shared_ptr<ScopeLayer> child) {
  child->parent_ = shared_from_this();
  children_.push_back(std::move(child));
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetParent() const {
  return parent_.lock();
}