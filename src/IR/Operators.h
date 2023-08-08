#pragma once

#include <memory>

#include "Instruction.h"
#include "Type.h"
namespace ir
{

    class BinaryOperator : public Instruction
    {
    public:
        BinaryOperator(std::shared_ptr<Type> type, std::string name)
            : Instruction(std::move(type), std::move(name), 2) { value_type_ = ValueType::BinaryOperator; };
    };

    class Add : public Instruction
    {
    public:
        explicit Add(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isInt() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isInt())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
            }
            else
            {
                throw std::runtime_error("Add: Invalid operand types");
            }
            value_type_ = ValueType::Add;
        };

        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "add " + operands_[0].getValue()->getName() + ", " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class FAdd : public Instruction
    {
    public:
        explicit FAdd(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isFloat() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isFloat())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
            }
            else
            {
                throw std::runtime_error("FAdd: Invalid operand types");
            }
            value_type_ = ValueType::FAdd;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "fadd " + operands_[0].getValue()->getName() + ", " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class Sub : public Instruction
    {
    public:
        explicit Sub(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isInt() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isInt())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("Sub: Invalid operand types");
                }
            }
            value_type_ = ValueType::Sub;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = sub " + operands_[0].getValue()->getName() + ", " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class FSub : public Instruction
    {
    public:
        explicit FSub(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isFloat() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isFloat())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("FSub: Invalid operand types");
                }
            }
            value_type_ = ValueType::FSub;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "fsub " + operands_[0].getValue()->getName() + ", " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class Mul : public Instruction
    {
    public:
        explicit Mul(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isInt() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isInt())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("Mul: Invalid operand types");
                }
            }
            value_type_ = ValueType::Mul;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "mul " + operands_[0].getValue()->getName() + ", " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class FMul : public Instruction
    {
    public:
        explicit FMul(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isFloat() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isFloat())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("FMul: Invalid operand types");
                }
            }
            value_type_ = ValueType::FMul;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "fmul " + operands_[0].getValue()->getName() + " * " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class SDiv : public Instruction
    {
    public:
        explicit SDiv(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isInt() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isInt())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("SDiv: Invalid operand types");
                }
            }
            value_type_ = ValueType::SDiv;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "sdiv " + operands_[0].getValue()->getName() + " / " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class FDiv : public Instruction
    {
    public:
        explicit FDiv(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isFloat() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isFloat())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("FDiv: Invalid operand types");
                }
            }
            value_type_ = ValueType::FDiv;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "fdiv " + operands_[0].getValue()->getName() + " / " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

    class SRem : public Instruction
    {
    public:
        explicit SRem(std::shared_ptr<User> opleft, std::shared_ptr<User> opright, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2)
        {
            setType(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32));
            if (opleft->getType()->isPrimitive() && opright->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<PrimitiveDataType>(opleft->getType())->isInt() && std::dynamic_pointer_cast<PrimitiveDataType>(opright->getType())->isInt())
                {
                    operands_.push_back(Use(opleft, this));
                    operands_.push_back(Use(opright, this));
                }
                else
                {
                    throw std::runtime_error("SRem: Invalid operand types");
                }
            }
            value_type_ = ValueType::SRem;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = " + "srem " + operands_[0].getValue()->getName() + " % " + operands_[1].getValue()->getName();
            helper.add(output);
            return output;
        };
    };

}