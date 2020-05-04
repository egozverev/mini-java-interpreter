#pragma once

class Statement {
public:
  virtual void execute() const = 0;
};