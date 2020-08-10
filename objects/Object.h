#pragma once

#include <memory>

enum Types{
  UNINIT,
  VOID,
  BOOLEAN,
  INT,
  USERTYPE
};

class Object {
public:
  Object() = default;

  explicit Object(Types type);

  ~Object() = default;

  int ToInt();

  bool ToBool();

  void SetValue(int value);

  void SetType(Types type);

  void SetType(const std::string& type);

  Types GetType();

private:
  int value_ = 0;
  Types type_ = UNINIT;
};