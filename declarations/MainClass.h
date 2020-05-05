#pragma once

#include "statements/StatementList.h"
#include "BaseElement.h"


class MainClass: BaseElement{
public:
  explicit MainClass(StatementList* statement_list);

  //void perform_body() const;

  void Accept(Visitor *visitor) override;

  StatementList* GetStatementList();

private:
  StatementList* statement_list_;
};