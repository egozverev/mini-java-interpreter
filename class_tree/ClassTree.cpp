#include "ClassTree.h"


std::shared_ptr<ClassNode> ClassTree::GetNode(const std::string &name) const {
  return class_mapping_.at(name);
}

void ClassTree::AddMapping(std::string name, std::shared_ptr<ClassNode> node) {
  class_mapping_[std::move(name)] = std::move(node);
}