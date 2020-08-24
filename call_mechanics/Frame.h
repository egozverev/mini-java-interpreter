#pragma once

#include "grammar/values/Types.h"
#include "objects/Object.h"

#include <memory>
#include <stack>

namespace calls {
  class Frame {
  public:
    explicit Frame(size_t param_size);
    void SetParams(const std::vector<Object>& values);

    size_t AllocVariable();

    void DeallocScope();
    void AllocScope();

    Object Get(long long index) const;

    void Set(long long index, const Object& value);

    void SetParentFrame(std::shared_ptr<Frame> frame);

    Object GetReturnValue() const;

    void SetParentReturnValue(const Object& value);

    void SetReturnValue(const Object& value);

    bool HasParent();

  private:
    std::stack<size_t> offsets_; // ~ ebp in x86
    std::vector<Object> params_;
    std::vector<Object> variables_;

    Object return_value_;


    std::shared_ptr<Frame> parent_frame = nullptr;

  };
}