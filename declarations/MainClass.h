#pragma once

#include "statements/StatementList.h"

class MainClass{
public:
  explicit MainClass(StatementList* statement_list);

  void perform_body() const;

private:
  StatementList* statement_list_;
};