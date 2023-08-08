#pragma once

#include <memory>
#include <vector>
#include <string>
#include <map>

#include "Instruction.h"
#include "MemoryAccess.h"

namespace ir
{

    class BasicBlock;
    class Function : public User
    {
    public:
        Function(std::shared_ptr<Type> type, std::string name)
            : User(std::move(type), std::move(name))
        {
            is_function_ = true;
            value_type_ = ValueType::Function;
        };
        std::string dump(DumpHelper &helper) const override;
        void addBasicBlock(std::shared_ptr<BasicBlock> basic_block);
        std::vector<std::shared_ptr<BasicBlock>> getBasicBlocks();

        void setExtern(bool is_extern)
        {
            if (is_extern)
            {
                basic_blocks_.clear();
            }
            is_extern_ = is_extern;
        };

        bool isExtern() const
        {
            return is_extern_;
        };

        void addArgument(std::shared_ptr<Allocate> argument)
        {
            arguments_.push_back(argument);
        }

        std::vector<std::shared_ptr<Allocate>> getArguments()
        {
            return arguments_;
        }

    protected:
        bool is_extern_ = false;
        std::vector<std::shared_ptr<BasicBlock>> basic_blocks_;
        std::vector<std::shared_ptr<Allocate>> arguments_;
    };

    class CompUnit : public User
    {
    public:
        CompUnit(std::shared_ptr<Type> type, std::string name)
            : User(std::move(type), name)
        {
            value_type_ = ValueType::CompUnit;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = "CompUnit " + getName() + " ";
            helper.add(output);
            helper.indent();
            for (auto global_object : global_objects_)
            {
                global_object.getValue()->dump(helper);
            }
            helper.unindent();
            return output;
        }

        void addGlobalObject(std::shared_ptr<User> global_object)
        {
            global_objects_.push_back(Use(std::move(global_object), this));
        }

        std::shared_ptr<std::vector<Use>> getGlobalObjects()
        {
            return std::make_shared<std::vector<Use>>(global_objects_);
        }

        std::shared_ptr<Function> getFunction(std::string name);

    protected:
        std::vector<Use> global_objects_;
    };

    class Icmp : public Instruction
    {
    public:
        enum class IcmpId
        {
            EQ,
            NE,
            GT,
            GE,
            LT,
            LE,
            Default,
        };

        explicit Icmp(IcmpId cid, std::shared_ptr<Value> lhs, std::shared_ptr<Value> rhs, std::string name)
            : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), std::move(name), 2), lhs_(lhs, this), rhs_(rhs, this), comp_id_(cid)
        {
            value_type_ = ValueType::Icmp;
        };

        std::string getOperatorLiterial(IcmpId id) const
        {
            switch (id)
            {
            case IcmpId::EQ:
                return "==";
            case IcmpId::NE:
                return "!=";
            case IcmpId::GT:
                return ">";
            case IcmpId::GE:
                return ">=";
            case IcmpId::LT:
                return "<";
            case IcmpId::LE:
                return "<=";
            default:
                throw std::runtime_error("Unknown IcmpId");
            }
        }

        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = icmp " + lhs_.getValue()->getName() + " " + getOperatorLiterial(comp_id_) + " " + rhs_.getValue()->getName() + " ";
            helper.add(output);
            return output;
        }

    protected:
        Use lhs_;
        Use rhs_;
        IcmpId comp_id_ = IcmpId::EQ;
    };

    class Fcmp : public Instruction
    {
    public:
        enum class FcmpId
        {
            EQ,
            NE,
            GT,
            GE,
            LT,
            LE,
            Default,
        };

        explicit Fcmp(FcmpId cid, std::shared_ptr<Value> lhs, std::shared_ptr<Value> rhs, std::string name)
            : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), std::move(name), 2), lhs_(lhs, this), rhs_(rhs, this), comp_id_(cid)
        {
            value_type_ = ValueType::Fcmp;
        };

        std::string getOperatorLiterial(FcmpId id) const
        {
            switch (id)
            {
            case FcmpId::EQ:
                return "==";
            case FcmpId::NE:
                return "!=";
            case FcmpId::GT:
                return ">";
            case FcmpId::GE:
                return ">=";
            case FcmpId::LT:
                return "<";
            case FcmpId::LE:
                return "<=";
            default:
                throw std::runtime_error("Unknown FcmpId");
            }
        }

        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " fcmp " + lhs_.getValue()->getName() + " " + getOperatorLiterial(comp_id_) + " " + rhs_.getValue()->getName() + " ";
            helper.add(output);
            return output;
        }

    protected:
        Use lhs_;
        Use rhs_;
        FcmpId comp_id_ = FcmpId::EQ;
    };

    class Return : public Instruction
    {
    public:
        Return(std::shared_ptr<User> retVal, std::string name)
            : Instruction(retVal->getType(), name, 1), ret_val_(retVal, this)
        {
            is_terminate_inst_ = true;
            value_type_ = ValueType::Return;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = "ret " + ret_val_.getValue()->getName() + " ";
            helper.add(output);
            return output;
        }

    protected:
        Use ret_val_;
    };

    class JPLabel : public Instruction
    {
    public:
        explicit JPLabel(std::string label_name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), label_name, 0), label_name_(label_name)
        {
            value_type_ = ValueType::JPLabel;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = "JPLabel " + getName() + ": ";
            helper.add(output);
            return output;
        }

    protected:
        std::string label_name_;
    };

    class Label : public Instruction
    {
    public:
        explicit Label(std::shared_ptr<JPLabel> jplabel) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), jplabel->getName(), 0), jplabel_(jplabel)
        {
            value_type_ = ValueType::Label;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = "label " + getName() + "";
            // helper.add(output);
            return output;
        }

        std::shared_ptr<JPLabel> getJPLabel()
        {
            return jplabel_;
        }

    protected:
        std::shared_ptr<JPLabel> jplabel_;
    };

    class Call : public Instruction
    {
    public:
        explicit Call(std::shared_ptr<Function> callee, std::vector<std::shared_ptr<User>> args, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 2), callee_(callee)
        {
            for (auto &arg : args)
            {
                args_.push_back(Use(arg, this));
            }
            value_type_ = ValueType::Call;
        };
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = getName() + " = call " + callee_->getName() + ", ";
            for (auto &arg : args_)
            {
                output += arg.getValue()->getName() + ", ";
            }
            helper.add(output);
            return output;
        }

    protected:
        std::shared_ptr<Function> callee_;
        std::vector<Use> args_ = std::vector<Use>();
    };

    class Br : public Instruction
    {
    public:
        Br(std::shared_ptr<Value> condition, std::shared_ptr<Label> t_label, std::shared_ptr<Label> f_label, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), std::move(name), 1), has_condition_(true), condition_(condition, this), t_label_(t_label, this), f_label_(f_label, this)
        {
            is_terminate_inst_ = true;
            value_type_ = ValueType::Br;
        };
        Br(std::shared_ptr<Label> t_label, std::string name) : Instruction(MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Void), name, 0), t_label_(t_label, this)
        {
            is_terminate_inst_ = true;
            value_type_ = ValueType::Br;
        };
        std::string dump(DumpHelper &helper) const
        {
            std::string output = "br ";
            if (has_condition_)
            {
                output += condition_.getValue()->getName() + ", " + t_label_.getValue()->dump(helper) + ", " + f_label_.getValue()->dump(helper) + " ";
            }
            else
            {
                output += t_label_.getValue()->dump(helper) + " ";
            }
            helper.add(output);
            return output;
        }
        bool hasCondition()
        {
            return has_condition_;
        }
        void setCondition(std::shared_ptr<Value> condition)
        {
            condition_ = Use(condition, this);
            has_condition_ = true;
        }
        std::shared_ptr<Value> getCondition()
        {
            return condition_.getValue();
        }

        std::shared_ptr<Label> getTLabel()
        {
            return std::dynamic_pointer_cast<Label>(t_label_.getValue());
        }
        std::shared_ptr<Label> getFLabel()
        {
            return std::dynamic_pointer_cast<Label>(f_label_.getValue());
        }

    protected:
        bool has_condition_ = false;
        Use condition_ = Use();
        Use t_label_ = Use();
        Use f_label_ = Use();
    };
}
