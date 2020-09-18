#include "ClassNode.h"

ClassNode::ClassNode(std::string name): class_name_(std::move(name)) {}

void ClassNode::AddParent(std::shared_ptr<ClassNode> parent) {
  parent_ = parent ;
}

void ClassNode::AddChild(std::shared_ptr<ClassNode> child) {
  std::string name = child->GetName();
  children_[std::move(name)] = std::move(child);
}

void ClassNode::AddVariable(std::string name, std::shared_ptr<ast::Type> type) {
  var_types_[std::move(name)] = std::move(type);
}

void ClassNode::AddFunction(std::string name, std::shared_ptr<ast::Function> func) {
  functions_[std::move(name)] = std::move(func);
}

void ClassNode::AddScope(std::string name, std::shared_ptr<ScopeLayer> scope) {
  function_scopes_[std::move(name)] = std::move(scope);
}

std::string ClassNode::GetName() const {
  return class_name_;
}

const std::unordered_map<std::string, std::shared_ptr<ast::Type> >& ClassNode::GetVars() const {
  return var_types_;
}

std::weak_ptr<ClassNode> ClassNode::GetParent() const {
  return parent_;
}

std::shared_ptr<ClassNode> ClassNode::GetChild(const std::string& name) const{
  return children_.at(name);
}

std::shared_ptr<ast::Type> ClassNode::GetVarType(const std::string &name) const {
  return var_types_.at(name);
}

std::shared_ptr<ast::Function> ClassNode::GetFunction(const std::string &name) const {
  return functions_.at(name);
}

std::shared_ptr<ScopeLayer> ClassNode::GetScope(const std::string& name) const {
  return function_scopes_.at(name);
}

bool ClassNode::HasFunction(const std::string& name) {
  return functions_.find(name) != functions_.end();
}

bool ClassNode::HasVariable(const std::string& name) {
  return var_types_.find(name) != var_types_.end();
}