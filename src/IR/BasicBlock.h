#pragma once

#include <memory>
#include <optional>
#include <string>

#include "Instruction.h"
#include "ControlFlow.h"
namespace ir
{
  class BasicBlock : public User, std::enable_shared_from_this<BasicBlock>
  {
  public:
    enum class BlockType
    {
      Default,
      FunctionEntry,
      IfTrue,
      IfFalse,
      WhileEntry,
      WhileBody

    };

    explicit BasicBlock(const std::string &name) : BasicBlock(name, BlockType::FunctionEntry){value_type_=ValueType::BasicBlock;};
    explicit BasicBlock(const std::string &name, BlockType type) : BasicBlock(std::make_shared<JPLabel>(name), type){value_type_=ValueType::BasicBlock;};
    explicit BasicBlock(std::shared_ptr<JPLabel> jplabel, BlockType type) : User(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), jplabel->getName()), jplabel_(jplabel), block_type_(type){value_type_=ValueType::BasicBlock;};
    std::string getStringifyBlockType() const
    {
      switch (block_type_)
      {
      case BlockType::Default:
        return "Default";
      case BlockType::FunctionEntry:
        return "FunctionEntry";
      case BlockType::IfTrue:
        return "IfTrue";
      case BlockType::IfFalse:
        return "IfFalse";
      case BlockType::WhileEntry:
        return "WhileEntry";
      case BlockType::WhileBody:
        return "WhileBody";
      }
      return "Unknown";
    };
    std::string dump(DumpHelper &helper) const override
    {
      auto s =  getName() + ":";
      helper.add(s);
      helper.indent();
      for (auto &inst : instructions_)
      {
        inst->dump(helper);
      }
      helper.unindent();
      return s;
    };

    std::shared_ptr<JPLabel> getJPLabel();

    void addInstruction(std::shared_ptr<Instruction> inst)
    {
    //   inst->setParent(shared_from_this());
      instructions_.push_back(inst);
    };
    std::vector<std::shared_ptr<Instruction>> getInstructions() const
    {
      return instructions_;
    }
    BlockType getBlockType() const
    {
      return block_type_;
    }

    std::optional<std::shared_ptr<Instruction>> getTerminator()
    {
      if (instructions_.empty())
      {
        return std::nullopt;
      }
      auto last = instructions_.back();
      if (last->isTerminator())
      {
        return last;
      }
      else
      {
        return std::nullopt;
      }
    }

  protected:
    std::shared_ptr<JPLabel> jplabel_;
    std::vector<std::shared_ptr<Instruction>> instructions_ = std::vector<std::shared_ptr<Instruction>>();
    BlockType block_type_;
  };
  typedef BasicBlock::BlockType BlockType;
}