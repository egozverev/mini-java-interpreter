#pragma once

#include <vector>
#include "grammar/program_base/BaseElement.h"

#include <memory>

namespace ast {
  class ParamValueList : public BaseElement, public std::enable_shared_from_this<ParamValueList> {
  public:
    ParamValueList() = default;

    explicit ParamValueList(std::shared_ptr<Expression> param);

    void Accept(Visitor &visitor) override;

    void AddParam(std::shared_ptr<Expression> expression);

    std::vector<std::shared_ptr<Expression>> &GetParams();

  private:
    std::vector<std::shared_ptr<Expression>> params_;
  };

}

