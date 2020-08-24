#pragma once

#include "ClassNode.h"

class ClassTree {
public:
  void AddMapping(std::string name, std::shared_ptr<ClassNode> node);

  std::shared_ptr<ClassNode> GetNode(const std::string& name) const;
private:
  std::unordered_map<std::string, std::shared_ptr<ClassNode>> class_mapping_;

};