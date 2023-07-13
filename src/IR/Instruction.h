#pragma once

#include <memory>

#include "User.h"
#include "BasicBlock.h"

namespace ir
{
  class Instruction : public User
  {
  public:
    Instruction(std::unique_ptr<Type> type, std::string name, unsigned numOps)
      : User(std::move(type), name), numOps_(numOps) {};
    Instruction(std::unique_ptr<Type> type, std::string name, unsigned numOps, std::shared_ptr<BasicBlock> parent):
      User(std::move(type), name), numOps_(numOps), parent_(parent) {};
      
    void setParent(std::shared_ptr<BasicBlock> parent) { parent_ = parent; };
    std::shared_ptr<BasicBlock> getParent() { return parent_; };
    void removeFromParent() { 
      //TODO
    };
  protected:
    unsigned numOps_;
    std::shared_ptr<BasicBlock> parent_;
  };
}