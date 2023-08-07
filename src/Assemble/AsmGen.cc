#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "AsmGen.h"
#include "IR/BasicBlock.h"
#include "IR/ControlFlow.h"
namespace asmgen
{

    void AsmGenerator::generate()
    {
        genCompUnit(comp_unit_);
    }

    std::string AsmGenerator::globalStaticValue(std::shared_ptr<ir::StaticValue> node)
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

    std::string AsmGenerator::memStaticValue(std::shared_ptr<ir::StaticValue> node){
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

    void AsmGenerator::genCompUnit(std::shared_ptr<ir::CompUnit> node)
    {
        auto global_objects = node->getGlobalObjects();
        for (auto global_object : *global_objects)
        {
            if (global_object.getValue()->getValueType() == ir::ValueType::Function)
            {
                auto function = std::dynamic_pointer_cast<ir::Function>(global_object.getValue());
                text_ << function->getName() << ":" << std::endl;
                auto basic_blocks = function->getBasicBlocks();
                for (auto basic_block : *basic_blocks)
                {
                    text_ << basic_block->getName() << ":" << std::endl;
                    auto instructions = basic_block->getInstructions();
                }
            }
            else if (global_object.getValue()->getValueType() == ir::ValueType::Allocate)
            {
                auto allocate = std::dynamic_pointer_cast<ir::Allocate>(global_object.getValue());
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
        }

        construct();
    }

    void AsmGenerator::construct()
    {
        s_ << ".data" << std::endl;
        s_ << data_.str() << std::endl;
        s_ << ".bss" << std::endl;
        s_ << bss_.str() << std::endl;
        s_ << ".text" << std::endl;
        s_ << text_.str() << std::endl;
    }

    std::string AsmGenerator::exportToString()
    {
        return s_.str();
    }

    void AsmGenerator::exportToFile(std::string path)
    {
        std::ofstream outfile;
        outfile.open("a.s", std::ios::out | std::ios::trunc);
        outfile.close();
    }
}