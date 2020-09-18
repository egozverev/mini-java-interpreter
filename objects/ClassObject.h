#pragma once

#include "Object.h"

#include <map>

class ClassObject: public Object {
public:
  explicit ClassObject(std::string name);

  std::string GetTypeName();

  void AddVariable(const std::string& name, const Object& value);

  bool HasVariable(const std::string& name);

  Object GetVariable(const std::string& name);

  void SetVariable(const std::string& name, const Object& value);

  bool IsClassObj() override;
private:
  std::map<std::string, Object> variables_;
  std::string typename_;
};