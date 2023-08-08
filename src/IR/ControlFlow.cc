#include "ControlFlow.h"
#include "BasicBlock.h"

namespace ir
{

    std::shared_ptr<Function> CompUnit::getFunction(std::string name)
    {
        for (auto global_object : global_objects_)
        {
            if (global_object.getValue()->getName() == name)
            {
                if (global_object.getValue()->getValueType() == ValueType::Function)
                {
                    return std::dynamic_pointer_cast<Function>(global_object.getValue());
                }
                throw std::runtime_error("getFunction: " + name + " is not a function");
            }
        }
        throw std::runtime_error("getFunction: " + name + " not found");
    }

    std::string Function::dump(DumpHelper &helper) const
    {
        std::string output = "function " + getType()->dump() + " " + getName() + "(";
        for (auto arg : arguments_)
        {
            output += arg->getName() + ", ";
        }
        output+="):";
        helper.add(output);
        helper.indent();
        for (auto basic_block : basic_blocks_)
        {
            basic_block->dump(helper);
        }
        helper.unindent();
        return output;
    }
    void Function::addBasicBlock(std::shared_ptr<BasicBlock> basic_block)
    {
        basic_blocks_.push_back(basic_block);
    }
    std::vector<std::shared_ptr<BasicBlock>> Function::getBasicBlocks()
    {
        return basic_blocks_;
    }

}