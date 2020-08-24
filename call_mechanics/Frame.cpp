#include "Frame.h"

namespace calls {
  Frame::Frame(size_t param_size) {
    params_.resize(param_size);

    AllocScope();
  }

  void Frame::SetParams(const std::vector<Object> &values) {
    if (params_.size() != values.size()) {
      throw std::runtime_error("Mismatched number of arguments");
    }
    params_ = values;
  }

  size_t Frame::AllocVariable() {
    size_t index = variables_.size();
    variables_.emplace_back();

    return index;
  }

  void Frame::DeallocScope() {
    size_t new_size = offsets_.top();
    offsets_.pop();
    variables_.resize(new_size);
  }

  void Frame::AllocScope() {
    offsets_.push(variables_.size());
  }

  Object Frame::Get(long long index) const {
    if (index >= 0) {
      return variables_.at(index);
    } else {
      return params_.at(-index - 1);
    }
  }

  void Frame::Set(long long index, const Object& value) {
    if (index >= 0) {
      variables_.at(index) = value;
    } else {
      params_.at(-index - 1) = value;
    }
  }

  void Frame::SetReturnValue(const Object& value) {
    return_value_ = value;
  }

  void Frame::SetParentFrame(std::shared_ptr<Frame> frame) {
    parent_frame = std::move(frame);

  }

  void Frame::SetParentReturnValue(const Object& value) {
    parent_frame->return_value_ = value;

  }

  bool Frame::HasParent() {
    return parent_frame != nullptr;
  }

  Object Frame::GetReturnValue() const {
    return return_value_;
  }

}