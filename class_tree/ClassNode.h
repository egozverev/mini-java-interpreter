#pragma once

#include "grammar/values/Types.h"
#include "grammar/functions/Function.h"
#include "symbol_table/ScopeLayer.h"

#include <string>
#include <unordered_map>
#include <memory>

class ClassNode {
public:
  explicit ClassNode(std::string name);

  void AddParent(std::shared_ptr<ClassNode> parent);

  void AddChild(std::shared_ptr<ClassNode> child);

  void AddVariable(std::string name, std::shared_ptr<ast::Type> type);

  void AddFunction(std::string name, std::shared_ptr<ast::Function> func);

  void AddScope(std::string name, std::shared_ptr<ScopeLayer> scope);

  std::string GetName() const;

  const std::unordered_map<std::string, std::shared_ptr<ast::Type>>& GetVars() const;

  std::weak_ptr<ClassNode> GetParent() const;

  std::shared_ptr<ClassNode> GetChild(const std::string& name) const;

  std::shared_ptr<ast::Type> GetVarType(const std::string& name) const;

  std::shared_ptr<ast::Function> GetFunction(const std::string& name) const;

  std::shared_ptr<ScopeLayer> GetScope(const std::string& name) const;

  bool HasFunction(const std::string& name);

  bool HasVariable(const std::string& name);

private:
  std::string class_name_;
  std::unordered_map<std::string, std::shared_ptr<ClassNode>> children_;
  std::weak_ptr<ClassNode> parent_;
  std::unordered_map<std::string, std::shared_ptr<ast::Type>> var_types_;
  std::unordered_map<std::string, std::shared_ptr<ast::Function>> functions_;
  std::unordered_map<std::string, std::shared_ptr<ScopeLayer>> function_scopes_; // func_name -> scope

};