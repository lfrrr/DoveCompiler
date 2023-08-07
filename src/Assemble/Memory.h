#pragma once

#include <vector>
#include <unordered_map>
#include <cstdint>

#include "IR/Value.h"
#include "Utils/Counter.h"
#include "Operands.h"
namespace asmgen
{
    class MemoryManager
    {

    public:
        MemoryManager() = default;
        ~MemoryManager() = default;

        Operand newOperand(std::shared_ptr<ir::Value> value)
        {
            Operand operand = Operand();
            operand.setCount(counter_.next());
            return operand;
        }

    protected:
        utils::Counter counter_ = utils::Counter();
        std::vector<std::string> operands_;
    };

    class RegisterManager
    {
    public:
        RegisterManager() = default;
        ~RegisterManager() = default;

        Register newRegister(std::shared_ptr<ir::Type> type)
        {
            Register reg = Register();
            reg.setCount(counter_.next());
            return reg;
        }

    protected:
        utils::Counter counter_ = utils::Counter();
        std::vector<std::string> registers_;
    };

    class Register
    {
    public:
        Register() = default;
        ~Register() = default;

        void setCount(int32_t count)
        {
            count_ = count;
        };
        std::string getName() { return name_; };
        std::shared_ptr<ir::Value> getValue() { return value_; };
        void setValue(std::shared_ptr<ir::Value> value) { value_ = value; };

    protected:
        std::string name_;
        int32_t count_;
        int32_t size_;
        int32_t address_;
        std::shared_ptr<ir::Value> value_;
    };
}