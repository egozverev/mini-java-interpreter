#include "ParamValuesList.h"

namespace ast {
  void ParamValueList::AddParam(std::shared_ptr<Expression> expression) {
    params_.push_back(std::move(expression));
  }

  std::vector<std::shared_ptr<Expression> > & ParamValueList::GetParams() {
    return params_;
  }

  void ParamValueList::Accept(Visitor &visitor) {
    visitor.Visit(this->shared_from_this());
  }

  ParamValueList::ParamValueList(std::shared_ptr<Expression> param): params_{std::move(param)} {
  }
}