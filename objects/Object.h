#pragma once

#include <memory>
#include "grammar/values/Types.h"

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

  explicit Object(std::shared_ptr<ast::Type> type);

  ~Object() = default;

  virtual int ToInt();

  virtual bool ToBool();

  virtual void SetValue(int value);

  virtual void SetType(std::shared_ptr<ast::Type> type);

  virtual void SetType(const std::string& type);

  virtual std::shared_ptr<ast::Type> GetType();

  virtual bool IsClassObj();

protected:
  int value_ = 0;
  std::shared_ptr<ast::Type> type_;
};