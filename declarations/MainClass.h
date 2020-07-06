#pragma once

#include "statements/StatementList.h"
#include "BaseElement.h"

#include <memory>

class MainClass : BaseElement, public std::enable_shared_from_this<MainClass> {
public:
  explicit MainClass(std::shared_ptr<StatementList> statement_list);

  //void perform_body() const;

  void Accept(Visitor *visitor) override;

  std::shared_ptr<StatementList> GetStatementList();

private:
  std::shared_ptr<StatementList> statement_list_;
};