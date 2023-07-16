#pragma once

#include <memory>
#include <string>

#include "Instruction.h"

namespace ir
{
  class BasicBlock : public User, std::enable_shared_from_this<BasicBlock>
  {
  public:
    explicit BasicBlock(std::string name) :User(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name)){};
    std::string dump(DumpHelper &helper) const override
    {
      auto s = "BasicBlock " + getName();
      for (auto &inst : instructions_)
      {
        s += "\n\t" + inst.getValue()->dump(helper);
      }
      return s;
    };

    void addInstruction(std::shared_ptr<Instruction> inst)
    {
      inst->setParent(shared_from_this());
      instructions_.push_back(std::move(Use(inst, this)));
    };

  protected:
    std::vector<Use> instructions_;
  };
}