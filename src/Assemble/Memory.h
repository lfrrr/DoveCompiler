#pragma once

#include <vector>
#include <unordered_map>
#include <cstdint>
#include <memory>
#include <sstream>

#include "IR/Value.h"
#include "Utils/Counter.h"
#include "Operands.h"
#include "IR/ControlFlow.h"
#include "AsmGen.h"
namespace asmgen
{
    class MemoryManager
    {

    public:
        MemoryManager(std::shared_ptr<ir::Function> function)
        {
            allocate_size_ = calStackSizeWithName(function);
            param_size_ = calParamSize(function);
        };

        ~MemoryManager() = default;

        size_t calStackSizeWithName(std::shared_ptr<ir::Function> function)
        {
            size_t total_size = 0;
            auto bbs = function->getBasicBlocks();
            for (auto bb : bbs)
            {
                auto insts = bb->getInstructions();
                for (auto inst : insts)
                {
                    size_t size = inst->getType()->size();
                    total_size += size;
                    if (size != 0)
                    {
                        offset_map_[inst->getName()] = total_size;
                    }
                }
            }
            return total_size;
        }

        size_t calParamSize(std::shared_ptr<ir::Function> function)
        {
            size_t total_size = 0;
            auto params = function->getArguments();
            for (auto param : params)
            {
                total_size += param->getType()->size();
            }
            return total_size;
        }

        std::string allocateStack()
        {
            std::stringstream s;
            // save sp to fp
            s << "push {fp, lr}" << std::endl;
            s << "mov fp, sp" << std::endl;
            s << "sub sp, sp, #4" << std::endl;
            s << "sub sp, sp, #" << allocate_size_ << std::endl;
            s << "push {r1}" << std::endl;
            s << "push {r2}" << std::endl;
            s << "push {r3}" << std::endl;
            return s.str();
        }

        std::string releaseStack()
        {
            std::stringstream s;
            s << "pop {r3}" << std::endl;
            s << "pop {r2}" << std::endl;
            s << "pop {r1}" << std::endl;
            s << "add sp, sp, #" << allocate_size_ << std::endl;
            s << "add sp, sp, #4" << std::endl;
            s << "pop {fp, pc}" << std::endl;
            return s.str();
        }

        Operand newOperand(std::shared_ptr<ir::Value> value)
        {
            Operand operand = Operand();
            operand.setCount(counter_.next());
            return operand;
        }

    protected:
        utils::Counter counter_ = utils::Counter();
        std::vector<std::string> operands_;
        size_t allocate_size_;
        size_t param_size_;
        std::map<std::string, size_t> offset_map_;
    };

    class Register
    {
        enum class RawId
        {
            r0,
            r1,
            r2,
            r3,
            r4,
            r5,
            r6,
            r7,
            r8,
            r9,
            r10,
            r11,
            r12,
            r13,
            r14,
            r15,
            r16,
            r17,
            r18,
            r19,
            r20,
            r21,
            r22,
            r23,
            r24,
            r25,
            r26,
            r27,
            r28,
            r29,
            r30,
            r31,
        };
    };
}