#pragma once

#include <memory>
#include <string>
#include <sstream>

#include "IR/ControlFlow.h"
#include "IR/BasicBlock.h"
#include "Memory.h"

namespace asmgen
{
    class AsmGenerator
    {
    public:
        AsmGenerator(std::shared_ptr<ir::CompUnit> comp_unit) : comp_unit_(comp_unit){};
        ~AsmGenerator() = default;

        void construct()
        {
            s_ << ".data" << std::endl;
            s_ << data_.str() << std::endl;
            s_ << ".bss" << std::endl;
            s_ << bss_.str() << std::endl;
            s_ << ".text" << std::endl;
            s_ << text_.str() << std::endl;
        }

        std::string globalStaticValue(std::shared_ptr<ir::StaticValue> node)
        {
            std::stringstream s;
            if (node->isInt())
            {
                s << ".word " << node->getInt() << std::endl;
            }
            else if (node->isFloat())
            {
                s << ".word " << node->getFloat() << std::endl;
            }
            else if (node->isArray())
            {
                for (auto val : node->getArray())
                {
                    s << globalStaticValue(val);
                }
            }
            return s.str();
        }

        std::string memStaticValue(std::shared_ptr<ir::StaticValue> node)
        {
            std::stringstream s;
            if (node->isInt())
            {
                s << node->getInt() << std::endl;
            }
            else if (node->isFloat())
            {
                s << node->getFloat() << std::endl;
            }
            else if (node->isArray())
            {
                for (auto val : node->getArray())
                {
                    s << memStaticValue(val);
                }
            }
            return s.str();
        }

        void genGlobalDecl(std::shared_ptr<ir::Allocate> allocate)
        {

            if (allocate->isConst())
            {
                data_ << allocate->getName() << ":" << std::endl;
                auto init_value = allocate->getInitValue();
                data_ << globalStaticValue(init_value);
            }
            else
            {
                bss_ << allocate->getName() << ":" << std::endl;
                auto init_value = allocate->getInitValue();
                bss_ << globalStaticValue(init_value);
            }
        }

        void genFunction(std::shared_ptr<ir::Function> function)
        {
            if (function->isExtern())
            {
                text_ << ".extern " << function->getName() << std::endl;
            }
            else
            {
                text_ << function->getName() << ":" << std::endl;

                auto memManager = MemoryManager(function);
                text_ << memManager.allocateStack();

                auto basic_blocks = function->getBasicBlocks();
                for (auto basic_block : basic_blocks)
                {
                    text_ << basic_block->getName() << ":" << std::endl;
                    auto instructions = basic_block->getInstructions();
                }
                text_ << memManager.releaseStack();
            }
        }

        void genCompUnit(std::shared_ptr<ir::CompUnit> node)
        {
            auto global_objects = node->getGlobalObjects();
            for (auto global_object : *global_objects)
            {
                if (global_object.getValue()->getValueType() == ir::ValueType::Function)
                {
                    auto function = std::dynamic_pointer_cast<ir::Function>(global_object.getValue());
                    genFunction(function);
                }
                else if (global_object.getValue()->getValueType() == ir::ValueType::Allocate)
                {
                    auto allocate = std::dynamic_pointer_cast<ir::Allocate>(global_object.getValue());
                    genGlobalDecl(allocate);
                }
            }
        }

        void generate()
        {
            genCompUnit(comp_unit_);
            text_ << std::endl;
            text_ << ".extern exit" << std::endl;
            text_ << ".global _start" << std::endl;
            text_ << "_start:" << std::endl;
            text_ << "bl main" << std::endl;
            text_ << "bl exit" << std::endl;
            construct();
        }

        std::string exportToString();

        void exportToFile(std::string path);

    protected:
        std::shared_ptr<ir::CompUnit> comp_unit_;
        std::stringstream s_;
        std::stringstream data_;
        std::stringstream bss_;
        std::stringstream text_;
    };
}